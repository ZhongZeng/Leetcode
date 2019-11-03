/*
1247. Minimum Swaps to Make Strings Equal
Ranking of Weekly Contest 161
Rank	Name	Score	Finish Time 	Q1 (4)	Q2 (4)	Q3 (5)	Q4 (6)
912 / 6255	zhongzeng 	13	1:06:24	1:06:24 	0:40:20 	0:19:20

Company	JP Morgan Chase
Related Topic String, Greedy 

Test Cases:
"xx"
"yy"
"xy"
"yx"
"xx"
"xy"
"xxyyxyxyxx"
"xyyxyxxxyx"

Runtime: 0 ms
Memory Usage: 8.4 MB
*/

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int sw=0, xy=0, yx=0;
        for( int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x')  xy++;
                else    yx++;
            }
        }
        if((xy+yx)%2==1)    return -1;
        
        return xy/2+yx/2+(xy%2==1||yx%2==1?2:0);// 1 swap of 2 same diffs offset + swao "xy"&"yx"
    }
};
/*
//wrong solution
        int sw=0, x1=0, x2=0;
        for( int i=0; i<s1.size(); i++) x1+=s1[i]=='x';
        for( int i=0; i<s2.size(); i++) x2+=s2[i]=='x';
        if((x1+x2)%2==1||(s1.size()+s2.size()-x1-x2)%2==1)  return -1;
        for( int i=0; i<s1.size(); i++) sw+=s1[i]!=s2[i];
        return sw;
*/