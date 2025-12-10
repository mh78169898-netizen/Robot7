def test():
    print('A 지점 통과')
    yield 1
    print('B 지점 통과')
    yield 2
    print('C 지점 통과')
    yield 3

output = test()
#next()라는 함수 호출해 봅시다
print('D 지점 통과')
next(output)
next(output)
next(output)
