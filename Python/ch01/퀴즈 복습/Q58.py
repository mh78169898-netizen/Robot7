list내부의 중복 된 수가 몇개인지 구하기
numbers = [1,2,6,8,4,3,2,1,9,5,4,9,7,2,1,3,5,4,8,9,7,2,3]
counter = {}

numbers.sort()

for num in numbers:
    if num in counter:
        counter[num] += 1 #키 없는 값은?
    else:
        counter[num] = 1 #중요!!!
print(counter)
