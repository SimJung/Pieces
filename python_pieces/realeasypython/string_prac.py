print("UTF-8 :", '한'.encode("utf-8"))
print("EUC-KR :", '한'.encode('EUC-KR'))
print(b'\xed\x95\x9c'.decode('utf-8'))
print(b'\xc7\xd1'.decode('EUC-KR'))