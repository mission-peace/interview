# Problem: https://www.hackerrank.com/challenges/crush/problem
#  Score: 60


n, queries = map(int, input().split())

arr = [0 for i in range(n+2)]

for i in range(queries):
    start, finish, k = map(int, input().split())
    arr[start - 1] += k
    arr[finish] -= k

ans = 0
current = 0
for i in arr:
    current += i
    if current > ans:
        ans = current

print(ans)
