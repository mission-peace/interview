# Problem: https://www.hackerrank.com/challenges/frequency-queries/problem
#  Score: 40


from collections import defaultdict


arr = defaultdict(int)
frequencies = defaultdict(int)
result = []
for i in range(int(input())):
    command, value = map(int, input().split())
    if command == 1:
        arr[value] += 1
        frequencies[arr[value]] += 1
        frequencies[arr[value] - 1] -= 1
    if command == 2 and arr[value] != 0:
        arr[value] -= 1
        frequencies[arr[value]] += 1
        frequencies[arr[value] + 1] -= 1
    if command == 3:
        result.append(1 if frequencies[value] > 0 else 0)

for i in result:
    print(i)
