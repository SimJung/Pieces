class Cat:
    # 생성자
    def __init__(self, name):
        self.name = name

    def speak(self):
        print(self.name, "가 포효합니다.")

    def drink(self):
        print(self.name, "가 우유를 마십니다.")
        print(self.name, "가 낮잠을 잡니다.")