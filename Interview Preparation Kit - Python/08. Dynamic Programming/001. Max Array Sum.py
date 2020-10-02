# Problem: https://www.hackerrank.com/challenges/max-array-sum/problem
#  Score: 20


def max_subset_sum(arr):
    dp = list()
    dp.append(arr[0])
    dp.append(max(arr[:2]))
    ans = dp[-1]
    for i in arr[2:]:
        dp.append(max(i, dp[-2] + i, ans))
        ans = max(ans, dp[-1])
    return ans


n = int(input())
arr = list(map(int, input().split()))
print(max_subset_sum(arr))
