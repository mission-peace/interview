# Problem: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
#  Score: 50


from collections import defaultdict


for t in range(int(input())):
    s = input()
    substrings = defaultdict(int)

    for i in range(1, len(s)):
        for j in range(len(s) - i + 1):
            substrings[''.join(sorted(s[j:j+i]))] += 1

    ans = 0
    for key, value in substrings.items():
        ans += value*(value-1) // 2

    print(ans)
