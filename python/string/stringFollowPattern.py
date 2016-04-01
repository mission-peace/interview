# Check if the string follows a pattern

"""
Given a string and a pattern, does the string follow the given pattern
eg - String - "red black red"
    Pattern - "aba"

    result = True
"""


def wordPattern(str, pattern):
    if len(pattern) == 0 or len(str) == 0: return False

    word_list = str.split()
    pattern_list = list(pattern)
    if len(word_list) != len(pattern_list): return False

    w2p = {}
    p2w = {}
    for i in range(0, len(word_list)):
        w = word_list[i]
        p = pattern_list[i]
        if w in w2p and p in p2w:
            if w2p[w] != p or p2w[p] != w:
                return False
        else:
            p2w[p] = w
            w2p[w] = p

    return True

if __name__ == '__main__':
    print wordPattern("red black red", "aba")
