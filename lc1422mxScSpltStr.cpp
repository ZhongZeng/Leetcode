/*
1422. Maximum Score After Splitting a String

Ranking of Weekly Contest 186  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
2908 / 11684	zhongzeng 	7	0:27:10	 0:08:17  1	 0:22:10	

Company	Google
Related Topics	String

Test Cases:
"011101"
"00111"
"1111"
"00"

Runtime: 4 ms
Memory Usage: 6.6 MB
*/

class Solution {
public:
    int maxScore(string s) {
        // array, O(n) time, O(1) space
        int zero=0, one=0, max=0;
        for( int i=0; i<s.size(); i++){
            if(s[i]=='1')   one++;
        }
        for( int i=0; i<s.size()-1; i++){
            if(s[i]=='0')   zero++;
            else    one--;
            int t=zero+one;
            if(max<t)   max=t;
        }
        return max;
    }
};