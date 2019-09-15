/*
1189. Maximum Number of Balloons

Ranking of Weekly Contest 154  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
1975 / 6062	zhongzeng 	7	0:44:13	 0:07:08  1	 0:39:13		

Companies   
Wayfair
Related Topics 
Hash Table, String

Test Cases:
"nlaebolko"
"loonbalxballpoon"
"leetcode"
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int mn=INT_MAX;
        vector<int> vc(26,0), vl={0,1,11,13,14}, vr={1,1,2,1,2};
        for( int i=0; i<text.size(); i++)   vc[text[i]-'a']+=1;
        
        for( int i=0; i<vl.size(); i++) mn=(vc[vl[i]]/vr[i])<mn?(vc[vl[i]]/vr[i]):mn;
        
        return mn;
    }
};