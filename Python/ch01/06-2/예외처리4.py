number = int(input('정수 입력>' ))
if number > 0:
    raise NotImplementedError
else:
    raise NotImplementedError


-추가 버전-
try:
    number = int(input('정수 입력>' )) #1.정수가 아닌 값 입력시 오류 발생
    if number > 0:
        raise NotImplementedError #2.number가 양수면 예외 발생
    else:
        raise NotImplementedError #3.number가 0이거나 음수면 예외 발생
except:
    print('예외가 발생했습니다.')
