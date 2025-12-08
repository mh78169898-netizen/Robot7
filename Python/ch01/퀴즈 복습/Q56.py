1번:사칙연산
cul = str(input("연산자: "))
a = int(input("a = "))
b = int(input("b = "))

if cul == '+':
    print("결과: ",a + b)
elif cul == '-':
    print("결과: ",a - b)
elif cul == '*':
    print("결과: ",a * b)
elif cul == '/':
    print("결과: ",a / b)
else:
    print("다시 입력!!!!!")
2번:or문을 쓰지 않고 중첩 if문을 사용해서 판별
num = int(input("입력: "))

if num % 3 == 0:
     print("OK")
elif num % 5 ==0:
    print("OK")
else:
    print("NO!!!")
------------------------------
-억지로 중첩만든 ver-
num = int(input("입력: "))

if num % 3 == 0:
     print("OK")
else:
  if num % 5 ==0:
    print("OK")
else:
    print("NO!!!")
