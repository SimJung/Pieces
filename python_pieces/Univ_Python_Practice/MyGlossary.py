# MyGlossary.py

from tkinter import *

# 키 입력 함수:
def click():
    entered_text = entry.get()
    output.delete(0.0, END)
    try:
        definition = my_glossary[entered_text]
    except:
        definition = "단어의 정의를 찾을 수 없습니다."
    output.insert(END, definition)

def getQ():
    entry = list(my_glossary.keys())

##### 메인:
window = Tk()
window.title("My Coding Club Glossary")

button = Button(window, width=10, text="질문 얻기", bg="White", command=getQ)
button.grid(row=0, column=0, sticky=W)

button = Button(window, width=10, text="답 얻기", bg="White", command=click)
button.grid(row=0, column=1, sticky=E)


output1 = Text(window, width=30, wrap=WORD, bg = "light green")
output1.grid(row=1, column=0, sticky=W)

# 다른 레이블 생성
Label(window, text="\n정의:").grid(row=3, column=0, sticky=W)

# 텍스트 박스 생성
output = Text(window, width=75, height=6, wrap=WORD, background="light green")
output.grid(row=4, column=0, columnspan=2, sticky=W)

# 사전
my_glossary = {'알고리즘':'컴퓨터로 작업을 수행하기 위해 컴퓨터가 이해할 수 있도록 단계별로 설명해놓은 것',
               '버그':'프로그램이 적절하게 동작하는데 실패하거나 또는 전혀 동작하지 않는 원인을 제공하는 코드 조각',
               '2진수':'2진법으로 나타낸 숫자',
               '대화형 모드':'IDLE(Python IDE-통합개발환경)을 벗어나 코드를 저장하지 않고 테스트하고자 할 때 사용합니다.'}

my_glossary["함수"] = "재사용할 수 있는 코드 조각"

##### 메인 반복문 실행
window.mainloop()
