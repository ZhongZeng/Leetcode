/*
1221. Split a String in Balanced Strings

Related Topics	String, Greedy

Test Cases:
"RLRRLLRLRL"
"RLLLLRRRLR"
"LLLLRRRR"

Runtime: 4 ms
Memory Usage: 8.4 MB
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        // greedy; s[i]== 'L' || 'R'
        int sum=0, R=0;
        
        for( int i=0; i<s.size(); i++){
            if(s[i]=='R')   R++;
            else    R--;
            if(R==0)    sum++;
        }
        
        return sum;
    }
};