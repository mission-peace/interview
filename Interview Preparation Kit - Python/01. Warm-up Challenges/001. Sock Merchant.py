# Problem: https://www.hackerrank.com/challenges/sock-merchant/problem
# Score: 10


def sock_merchant(ar):
    list_of_socks = [0 for i in range(101)]
    for element in ar:
        list_of_socks[element] = list_of_socks[element] + 1
    ans = 0
    for sock in list_of_socks:
        ans += sock // 2
    return ans


n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = sock_merchant(ar)
print(result)
