/*
1309. Decrypt String from Alphabet to Integer Mapping

Weekly Contest 170
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (5)	Q3 (5)	Q4 (7)
2304 / 6833	zhongzeng Virtual	8	-4:0-20:0-2	 -4:0-45:0-47	 -4:0-20:0-2	

Company	Quip
Related Topics	String 

Test Cases:
"10#11#12"
"1326#"
"25#"
"12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 8.4 MB
*/

class Solution {
public:
    string freqAlphabets(string s) {
        string rt;
        for( int i=s.size()-1; -1<i; i--){
            if(s[i]=='#'){
                rt.push_back((char)(s[i-1]-'0'+(s[i-2]-'0')*10-10+'j'));
                i-=2;
            }else{
                rt.push_back((char)(s[i]-'0'-1+'a'));
            }
        }
        for( int i=0, j=rt.size()-1; i<j; i++, j--){
            char c=rt[i];
            rt[i]=rt[j];
            rt[j]=c;
        }
        return rt;
    }
};