# Problem: https://www.hackerrank.com/challenges/mark-and-toys/problem
#  Score: 35


n, k = map(int, input().split())
prices = sorted(list(map(int, input().split())))

count = 0
total_sum = 0
for i in prices:
    total_sum += i
    if total_sum > k:
        break
    else:
        count += 1
print(count)
