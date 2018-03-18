# MyMagic8Ball

import random

name = input("네 놈의 이름을 입력하라\n")

ans = ("Do it","Fuck off","Fucker","Idoit..","Lamb;","No","Get out of here","맞음")

print("이상한 게임에 온 걸 환영한다")

question = input("질문하시오\n")
print("고민 중..\n"*4)

square8 = random.randint(0,7)

print(ans[square8])

print(name, input("\n\nㅇㅋ 꺼져"))
