# Problem: https://www.hackerrank.com/challenges/minimum-swaps-2/problem
# Score: 40


n = int(input())
arr = list(map(int, input().split()))
count = 0

i = 0
while i < len(arr):
    if arr[i] != i + 1:
        arr[arr[i] - 1], arr[i] = arr[i], arr[arr[i] - 1]
        count += 1
    else:
        i += 1

print(count)
