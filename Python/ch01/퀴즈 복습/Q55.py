--성적 입력 코드--
num = int(input("성적을 입력하세요: "))

if num >= 90:
    print("A")
elif 89 >= num >= 80:
    print("B")
elif 79 >= num >= 70:
    print("C")
elif 69 >= num >= 60:
    print("D")
else:
    print("F")
