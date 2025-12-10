list_input_a = ['52','273','32','스파이','103'] #변수 선언

list_number = [] #반복 적용
for item in list_input_a: #숫자로 변환 후 리스트에 추가
    try:
        float(item)
        list_number.append(item) #예외 없이 통과하면 다음으로 진행
    except:
        pass  #예외가 발생하면 아무것도 안핟고 통과

print("{} 내부에 있는 숫자는".format(list_input_a))
print("{} 입니다.".format(list_number))
