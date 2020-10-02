# Problem: https://www.hackerrank.com/challenges/two-strings/problem
#  Score: 25


for i in range(int(input())):
    str1 = set(input())
    str2 = set(input())
    if str1 & str2 != set():
        print('YES')
    else:
        print('NO')
