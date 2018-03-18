#myEtchASketch 응용 프로그램

from tkinter import*

canvas_height = 400
canvas_width = 600
canvas_colour = "black"

p1_x = canvas_width/2
p1_y = canvas_height
p1_colour = "PaleVioletRed3"
line_width = 5
line_length = 5

##### 함수 :

def p1_move(x, y):
    global p1_x
    global p1_y

    canvas.create_line(p1_x, p1_y, p1_x + x, p1_y + y, width = line_width, fill = p1_colour)
    p1_x = p1_x + x
    p1_y = p1_y + y

def p1_move_N(event):
    p1_move(0, -line_length)

def p1_move_S(event):
    p1_move(0, line_length)

def p1_move_E(event):
    p1_move(line_length, 0)

def p1_move_W(event):
    p1_move(-line_length, 0)

##### main :

window = Tk()
window.title("MyEtchASketch")
canvas = Canvas(bg = canvas_colour, height = canvas_height, width = canvas_width, highlightthickness = 1)
canvas.pack()

window.bind("<Up>", p1_move_N)
window.bind("<Down>", p1_move_S)
window.bind("<Right>", p1_move_E)
window.bind("<Left>", p1_move_W)

window.mainloop()