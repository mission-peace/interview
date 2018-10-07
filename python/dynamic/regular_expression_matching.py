'''
10. Regular Expression Matching

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
'''
from pprint import pprint

class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        dpResults = [[False for i in range(0, len(p) +1)] for j in range(0, len(s) + 1)]

        #set the initial bit, pseudo state
        dpResults[0][0] = True
 
        #refine the dpResults to account for cases where the pattern is a* or <anything>*<anything>*
        for i in range(1, len(dpResults[0])):
            if p[i-1] == '*':
                dpResults[0][i] = dpResults[0][i-2]

        #meat, we start from 1; be careful with how the s and p are indexed differently than the dpResults result matrix
        for i in range(1, len(dpResults)):
            for j in range(1, len(dpResults[0])):
                #print(i,j)
                #print(s,p)
                #case 1
                #where the iterator value of the string matches that of the pattern; we will directly use the value of 
                #results when both these values didn't exist.
                if s[i-1] == p[j-1] or p[j-1] == '.':
                    dpResults[i][j] = dpResults[i-1][j-1]

                #case 2
                #when the pattern is *
                elif p[j-1] == '*':
                    #lets consider the state where the <something>* don't exist
                    dpResults[i][j] = dpResults[i][j-2]
                    #condition where above value could be false, let's check if atleast once occurence of <something> is availble in the string
                    if p[j-2] == s[i-1] or p[j-2]== '.':
                        #considering the above was false, and the <something> matches the pertinent value in the string lets grab the value when cooresponding 
                        #string element didn't exist
                        dpResults[i][j] = dpResults[i][j] or dpResults[i-1][j]                
                #case 3
                #nothing matches, its an obvious false
                else:
                    dpResults[i][j] = False
        return dpResults[-1][-1]
        # or return dpResults[i][j]


obj = Solution()
print(obj.isMatch('abcd', 'a.c*d*'))
print(obj.isMatch('aa', 'a'))
print(obj.isMatch('aa', 'a*'))
print(obj.isMatch('ab', '.*'))
print(obj.isMatch('aab', 'c*a*b'))
print(obj.isMatch('mississippi', 'mis*is*p*.'))