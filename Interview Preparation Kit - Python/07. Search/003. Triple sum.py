# Problem: https://www.hackerrank.com/challenges/triple-sum/problem
#  Score: 40


def binary_search_last(arr, el, low, high):
    if low + 1 >= high:
        if arr[low] > el:
            return 0
        else:
            return low + 1
    middle = (low + high) // 2
    if arr[middle] > el:
        return binary_search_last(arr, el, low, middle)
    else:
        return binary_search_last(arr, el, middle, high)


len_a, len_b, len_c = map(int, input().split())
a = sorted(set(map(int, input().split())))
b = sorted(list(set(map(int, input().split()))))
c = sorted(list(set(map(int, input().split()))))

ans = 0
for i in set(b):
    ans += binary_search_last(a, i, 0, len(a)) * binary_search_last(c, i, 0, len(c))
print(ans)
