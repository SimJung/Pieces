# MyPong의 주된 파일을 만듭니다.

from tkinter import *
import table, ball, bat

# 전역 변수 초기화
x_velocity = 0
y_velocity = -10
score_left = 0
score_right = 0
first_serve = True

# tkinter 공장으로부터 윈도우 주문
window = Tk()
window.title("MyInvaders~~")

# Table 공장으로부터 table 주문
my_table = table.Table(window)

starry_night_image = PhotoImage(file = "stars.gif")
my_table.canvas.create_image(0, 0, anchor = NW, image = starry_night_image, tags = "bg_img")

my_table.canvas.lower("bg_img")

# Ball 공장으로부터 볼을 주문합니다
my_ball = ball.Ball(table=my_table, x_speed=x_velocity, y_speed=y_velocity,
                    width=5, height=10, colour="red", x_start=-50, y_start=-50)

# Bat 공장으로부터 배트를 주문합니다
bat_B = bat.Bat(table=my_table, width=50, height=30, x_posn=20, y_posn=350, colour="blue")

colour = ["green", "orange", "white", "gray", "purple"]

# 적 우주선 소환
invaders = []
row = 0
for i in range(0, 30):
    if (i%6 == 0 and i >= 6):
        row += 1
    invaders.append(bat.Bat(table=my_table, width=50, height=20, x_posn=20+((i % 6)*60), y_posn=5+(row*25), colour=colour[row % 5], x_speed=3, y_speed=15))


# 다수의 총알을 발사하기 위한 배열
missles = []

#### 함수:
def game_flow():
    global first_serve
    # 첫번째 서브를 기다립니다:
    if(first_serve == True):
        my_ball.stop_ball()
        first_serve = False

    # 위쪽 벽에 공이 부딪치는지 감지
    for m in missles:
        if(m.y_posn <= 3):
            my_table.remove_item(m.circle)
            missles.remove(m)

    # 적들에게 공이 부딪치는지 감지:
    for i in invaders:
        for m in missles:
            if(i.detect_collision(m) != None):
                my_table.remove_item(i.rectangle)
                invaders.remove(i)
                my_table.remove_item(m.circle)
                missles.remove(m)

    for m in missles:
        m.move_next()

    window.after(50, game_flow)

# restart_game 함수는 여기에 추가:
def restart_game(master):
    global missles
    missles.append(ball.Ball(table=my_table, x_speed=x_velocity, y_speed=y_velocity, width=5, height=10, colour="red", x_start=bat_B.x_posn + bat_B.width/2, y_start=bat_B.y_posn))

# 배트를 제어하기 위해 키보드의 키에 연결
window.bind("<Right>", bat_B.move_right)
window.bind("<Left>", bat_B.move_left)

# 스페이스바를 눌러 게임 재시작
window.bind("<space>", restart_game)

# game_flow 반복문 호출
game_flow()

# tkinter 반복문 프로세스 시작
window.mainloop()
