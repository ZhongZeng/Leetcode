/*
1446. Consecutive Characters

Easy
Related Topics	String
Similar Questions	Max Consecutive Ones

Runtime: 8 ms, faster than 90.95% of C++ online submissions for Consecutive Characters.
Memory Usage: 7 MB, less than 20.76% of C++ online submissions for Consecutive Characters.
Next challenges: Simplify Path, Palindrome Pairs, Add Bold Tag in String

*/

class Solution {
public:
    int maxPower(string s) {
        // Two Pointer, O(n) time
        int b=0, e=0, mx=0;// [b,e)
        while( e<s.size() ){            
            if(s[b]==s[e]){
                e++;
                mx=mx<e-b?e-b:mx;
            }else{
                b=e++;
            }
        }
        return mx;
    }
};