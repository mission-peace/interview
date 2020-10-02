# Problem: https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem
#  Score: 35


t = int(input())
for i in range(t):
    money = int(input())
    n = int(input())
    arr = list(map(int, input().split()))

    saved_values = {}
    for counter, value in enumerate(arr):
        if money-value in saved_values:
            print(saved_values[money-value] + 1, counter + 1)
        elif value not in saved_values:
            saved_values[value] = counter
