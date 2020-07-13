/*
1513. Number of Substrings With Only 1s

Medium
Companies	Google
Related Topics	Math, String

Test Cases:
"0110111"
"101"
"111111"
"000"

Runtime: 56 ms
Memory Usage: 8.7 MB
*/

class Solution {
public:
    int numSub(string s) {
        // Dynamic Programming, O(n) time, O(1) space 
        int sum=0, len=0;
        
        for( int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                len++;
                sum=(sum+len)%1000000007;
            }else{
                len=0;
            }
        }
        
        return sum;
    }
};