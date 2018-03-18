from datetime import datetime
hour = datetime.now().hour

#현재 시각이 12시보다 빠를 때만 print문을 실행하도록 다음 줄에 if문을 추가하세요.

if hour < 12:
	print("오전입니다.")
	
elif hour > 12:
	print("오후입니다.")
	
if hour%6 == 0:
	print("종이 울립니다..")