'''
Leetcode 10. Regular Expression Matching

Companies 
Google, Facebook, Uber, Twitter, Airbnb 
Related Topics 
String, Dynamic Programming, Backtracking 
Similar Questions 
Wildcard Matching

Test Cases:
"aa"
"a"
"aa"
"a*"
"ab"
".*"
"aab"
"c*a*b"
"mississippi"
"mis*is*p*."
"ab"
".*"
"aab"
"c*a*b"

Next challenges: Paint Fence, Smallest Range Covering Elements from K Lists, 
Maximum Sum of 3 Non-Overlapping Subarrays
Next challenges: Palindrome Pairs, Russian Doll Envelopes, 
Number of Submatrices That Sum to Target

Runtime: 24 ms
Memory Usage: 11.7 MB
Your runtime beats 97.00 % of python submissions.
Your memory usage beats 65.96 % of python submissions.
'''

class Solution(object):
    def helper(self, s, p, i_s, i_p):# s(,i_s] p(,i_p]; DP, Topological Sort 
        if (i_s,i_p) in self.memo:
            return self.memo[(i_s,i_p)]
        elif i_p==-1:# empty p only matches empty s
			self.memo[(i_s,i_p)]=i_s==-1 
        elif i_s==-1:# empty s only matches multiple "*"
            if p[i_p]=="*":
                self.memo[(i_s,i_p)]=self.helper(s,p,i_s,i_p-2)
            else:
                self.memo[(i_s,i_p)]=False
        elif s[i_s]==p[i_p] or p[i_p]==".":
			self.memo[(i_s,i_p)]=self.helper(s,p,i_s-1,i_p-1)
        #elif s[:i_s]==p[:i_p]:
        #    self.memo[(i_s,i_p)]=True
        #elif not s[:i_s] or not p[:i_p]:
        #    self.memo[(i_s,i_p)]=False
        elif p[i_p]=="*":
            if self.helper(s,p,i_s,i_p-2) == True:
                self.memo[(i_s,i_p)]=True
            else:
                if s[i_s]==p[i_p-1] or p[i_p-1]==".":
                    self.memo[(i_s,i_p)]=self.helper(s,p,i_s-1,i_p) 
                else:
                    self.memo[(i_s,i_p)]=False
        else:
            self.memo[(i_s,i_p)]=False
        return self.memo[(i_s,i_p)]
        
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        self.memo={}
        return self.helper(s,p,len(s)-1,len(p)-1) 