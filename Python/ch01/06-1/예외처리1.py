try:
    num = int(input('정수를 입력하세요: '))
    print(num)
except: #예외 처리 부분
    print('무언가 잘못 되었습니다.') #출력 후 안전하게 종료됨
