# Problem: https://www.hackerrank.com/challenges/minimum-time-required/problem
#  Score: 35


import math


def minimum_time(goal, machines):
    min_days = math.ceil(goal / (len(machines) / min(machines)))
    max_days = math.ceil(goal / (len(machines) / max(machines)))
    while min_days < max_days:
        day = (min_days + max_days) // 2
        if sum(day // i for i in machines) >= goal:
            max_days = day
        else:
            min_days = day + 1
    return min_days


n, goal = map(int, input().split())
machines = list(map(int, input().split()))
print(minimum_time(goal, machines))
