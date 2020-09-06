/*
1576. Replace All ?'s to Avoid Consecutive Repeating Characters

Ranking of Weekly Contest 205  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (5)	Q3 (5)	Q4 (6)
1903 / 13171	zhongzeng 	13	0:47:56	 0:20:47	 0:30:43  1	 0:42:56	

Easy
Companies	Microsoft
Related Topics	String

Test Cases:
"?zs"
"ubv?w"
"j?qg??b"
"??yw?ipkj?"

Runtime: 0 ms
Memory Usage: 6 MB
Your runtime beats 100.00 % of cpp submissions.
Your memory usage beats 83.33 % of cpp submissions.
*/

class Solution {
public:
    string modifyString(string s) {
        // O(n) time; an solution is guranteed 
        for( int i=0; i<s.size(); i++){
            if(s[i]=='?'){
                char c1=0<i?s[i-1]:'?', c2=i+1<s.size()?s[i+1]:'?';
                s[i]=getADiffChar(c1,c2);
            }
        }
        return s;
    }
    
protected:
    char getADiffChar( char c1, char c2){
        for( int i=0; i<3; i++){
            if('a'+i!=c1&&'a'+i!=c2)    return (char)('a'+i);
        }
        return '?';
    }
};