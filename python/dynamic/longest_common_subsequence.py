"""
Problem Statement
=================

Given two sequences A = [A1, A2, A3,..., An] and B = [B1, B2, B3,..., Bm], find the length of the longest common
subsequence.

Video
-----

* https://youtu.be/NnD96abizww

Complexity
----------

* Recursive Solution: O(2^n) (or O(2^m) whichever of n and m is larger).
* Dynamic Programming Solution: O(n * m)

Reference
---------

* https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
* http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
"""


def lcs_recursive_helper(sequence1, sequence2, index1, index2):
    if (index1 == len(sequence1)) or (index2 == len(sequence2)):
        return 0

    if sequence1[index1] == sequence2[index2]:
        return 1 + lcs_recursive_helper(sequence1, sequence2, index1 + 1, index2 + 1)

    return max(lcs_recursive_helper(sequence1, sequence2, index1 + 1, index2),
               lcs_recursive_helper(sequence1, sequence2, index1, index2 + 1))


def longest_common_subsequence_recursive(sequence1, sequence2):
    return lcs_recursive_helper(sequence1, sequence2, 0, 0)


def longest_common_subsequence(sequence1, sequence2):
    rows = len(sequence1) + 1   # Add 1 to represent 0 valued row for DP
    cols = len(sequence2) + 1   # Add 1 to represent 0 valued column for DP

    T = [[0 for _ in range(rows)] for _ in range(cols)]

    max_length = float("-inf")

    for index_i in range(1, rows):
        for index_j in range(1, cols):
            if sequence1[index_i - 1] == sequence2[index_j - 1]:
                T[index_j][index_i] = 1 + T[index_j - 1][index_i - 1]
            else:
                T[index_j][index_i] = max(T[index_j - 1][index_i], T[index_j][index_i - 1])

            max_length = max(max_length, T[index_j][index_i])

    return max_length


if __name__ == '__main__':
    sequence1 = "ABCDGHLQR"
    sequence2 = "AEDPHR"
    expected_length = 4
    assert expected_length == longest_common_subsequence_recursive(sequence1, sequence2)
    assert expected_length == longest_common_subsequence(sequence1, sequence2)
