1번: 리스트 원소들로 구현가능한 모든 쌍 출력.
num = [1,3,5,7]

for i in num:
    for j in num:
        print('({}, {})'.format(i,j))

print()
print()

2번:2차원 리스트의 원소의 합 출력(for 이중반복 구문을 꼭 사용)
array = [[1,2,3],[4,5,6],[7,8,9]]
array_sum = 0 #변수 초기화 부분이 있어야 정상 동작함

for i in array:
    for el in i:
        array_sum += el
print('합:',array_sum)
