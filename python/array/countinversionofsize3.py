"""
Problem Statement
=================

Given an array arr[] of size n. Three elements arr[i], arr[j] and arr[k] form an inversion of size 3
if a[i] > a[j] >a[k] and i < j < k. Find total number of inversions of size 3.


Approach
========

For each element i, we find the number of elements occurring earlier to i, which are greater in value and the number of
elements occurring later to i, which are smaller in value. We multiple those numbers, and add them for all the values of
i in the array.

Complexity
==========

* O(n^2)


Reference
=========

* http://www.geeksforgeeks.org/count-inversions-of-size-three-in-a-give-array/

"""


def find_num_inversions(arr):
    count = 0

    for i in range(1, len(arr) - 1):
        larger = 0
        for j in range(0, i):
            if arr[j] > arr[i]:
                larger += 1

        smaller = 0
        for k in range(i+1, len(arr)):
            if arr[k] < arr[i]:
                smaller += 1

        count += larger*smaller

    return count

if __name__ == '__main__':
    arr = [9, 6, 4, 5, 8]
    assert 2 == find_num_inversions(arr)
