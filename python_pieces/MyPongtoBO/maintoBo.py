# MyPong의 주된 파일을 만듭니다.

from tkinter import *
import table, ball, bat

# 전역 변수 초기화
x_velocity = 10
y_velocity = 10
first_serve = True

# tkinter 공장으로부터 윈도우 주문
window = Tk()
window.title("MyPong")
       
# Table 공장으로부터 table 주문
my_table = table.Table(window, net_colour="green")

# Ball 공장으로부터 볼을 주문합니다
my_ball = ball.Ball(table=my_table, x_speed=x_velocity, y_speed=y_velocity,
                    width=24, height=24, colour="red", x_start=288, y_start=188)

# Bat 공장으로부터 배트를 주문합니다
bat_B = bat.Bat(table=my_table, width = 100, height = 15, x_posn = 300, y_posn = 350, colour = "blue")

# 블록 생성
bricks = []
gap = 30
for i in range(0, 7):
    bricks.append(bat.Bat(table = my_table, width=50, height=30, x_posn=35 + (gap+50)*i, y_posn=50, colour="green"))

#### 함수:
def game_flow():
    global first_serve
    # 첫번째 서브를 기다립니다:
    if(first_serve == True):
        my_ball.stop_ball()
        first_serve = False
    
    # 배트가 공을 받아치는지 확인:
    bat_B.detect_collision(my_ball, topnbottom_sweet_spot=True)
    for b in bricks:
        if(b.detect_collision(my_ball) != None):
            my_table.remove_item(b.rectangle)
            bricks.remove(b)

        if(len(bricks) == 0):
            my_ball.stop_ball()
            my_ball.start_position()
            my_table.draw_score("", "you win!")


    # 공이 깨골창으로 빠지는지 감지:
    if(my_ball.y_posn + my_ball.height >= my_table.height - 3):
        my_ball.stop_ball()
        my_ball.start_position()
        bat_B.start_position()
        my_table.move_item(bat_B.rectangle, 250, 350, 350, 365)

        first_serve = True

    my_ball.move_next()
    window.after(50, game_flow)

# restart_game 함수는 여기에 추가:
def restart_game(master):
    my_ball.start_ball(x_speed= x_velocity, y_speed=y_velocity)

# 배트를 제어하기 위해 키보드의 키에 연결
window.bind("<Right>", bat_B.move_right)
window.bind("<Left>", bat_B.move_left)

# 스페이스바를 눌러 게임 재시작
window.bind("<space>", restart_game)

# game_flow 반복문 호출
game_flow()

# tkinter 반복문 프로세스 시작
window.mainloop()
