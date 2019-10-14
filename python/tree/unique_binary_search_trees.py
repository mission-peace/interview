'''
Author : MiKueen
Level : Medium
Problem Statement : Unique Binary Search Trees II
https://leetcode.com/problems/unique-binary-search-trees-ii/

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generate(self, s, e):
        res = []
        if s > e:
            res.append(None)
            return res
        for i in range(s, e+1):
            left = self.generate(s, i-1)
            right = self.generate(i+1, e)
            for l in left:
                for r in right:
                    root = TreeNode(i) 
                    root.left = l
                    root.right = r
                    res.append(root)
        return res      
    
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        return self.generate(1, n)
    