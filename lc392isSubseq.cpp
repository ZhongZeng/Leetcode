

/*
Leetcode 392. Is Subsequence



Related Topics 
Binary Search, Dynamic Programming, Greedy

Next challenges: Scramble String, IPO, Maximum Vacation Days

Test Cases:
"abc"
"ahbgdc"
"ahbgdc"
"abc"
""
""

Runtime: 69 ms
Your runtime beats 77.22 % of cpp submissions.

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // greedy, DP
        if(t.size()<s.size())   return false;
        
        int i=0, j=-1;
        while( ++j<t.size()){
            if(s[i]==t[j])  i++;
            if(i==s.size()) return true;
        }
        
        
        return i==s.size();
    }
};
