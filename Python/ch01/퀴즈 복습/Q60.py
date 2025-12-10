# 1번:짝수만 골라서 제곱 리스트 만들기
number = [1,2,3,4,5,6,7,8,9,10]
result = filter(lambda x : x % 2 == 0, number)
result2 = map(lambda y : y**2, result)
print(list(result2))

# 2번:문자열 리스트에서 길이가 5 이상인 단어의 길이 뽑아내기
words = ["python", "map", "filter", "lambda", "hi", "education", "code"]
result = filter(lambda x : len(x) > 5, words)
result2 = map(lambda y : len(y), result)
print(list(result2))

# 3번:학생 점수 중 60점 이상만 통과, +5보정점수
scores = [35,78,92,55,61,47,88,73]
grade = filter(lambda x : x > 60, scores)
grade2 = map(lambda y : y + 5, grade)
print(list(grade2))
