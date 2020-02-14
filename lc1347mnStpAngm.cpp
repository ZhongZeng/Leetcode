/*
1347. Minimum Number of Steps to Make Two Strings Anagram

Company	Twitter
Related Topics	String

Test Cases:
"bab"
"aba"
"leetcode"
"practice"
"anagram"
"mangaar"
"xxyyzz"
"xxyyzz"
"friend"
"family"


Runtime: 96 ms, faster than 49.29% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
Memory Usage: 18.9 MB, less than 100.00% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.

Next challenges:
Parse Lisp Expression, Brace Expansion II, Remove Sub-Folders from the Filesystem
*/

class Solution {
public:
    int minSteps(string s, string t) {
        // O(m+n) time; O(1) space; easy; s&t contains only 'a'-'z'
        int sum=0;
        vector<int> vc(26, 0);
        
        for( int i=0; i<s.size(); i++)  vc[s[i]-'a']+=1;
        for( int i=0; i<t.size(); i++)  vc[t[i]-'a']-=1;
        
        for( int i=0; i<vc.size(); i++){
            if(0<vc[i]) sum+=vc[i];
        }
        
        return sum;
    }
};