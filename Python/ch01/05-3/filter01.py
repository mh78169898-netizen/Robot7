# filter(함수, 리스트) #함수 부분을 람다식으로 표현 가능
num = [1,2,3,4,5]

# def is_odd(x):
#     return x % 2 != 0
# result = filter(is_odd,num)

result = filter(lambda x : x%2 !=0, num)

print(list(result))
