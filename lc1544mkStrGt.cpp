/*
1544. Make The String Great

Ranking of Weekly Contest 198 
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (5)	Q3 (6)	Q4 (7)
1573 / 15152	zhongzeng 	8	0:42:22	 0:16:46	 0:42:22	

Easy
Companies	Google
Related Topics	String, Stack

Test Cases:
"leEeetcode"
"abBAcC"
"s"

Runtime: 4 ms	Your runtime beats 83.33 % of cpp submissions.
Memory Usage: 6.3 MB
*/

class Solution {
public:
    string makeGood(string s) {
        if(s.empty())   return s;
        string t;
        
        for( int i=0; i<s.size(); i++){
            if(t.empty()||isGood(s[i], t.back() ))  t.push_back(s[i]);
            else    t.pop_back();
        }
        
        return t;
    }
    
protected:
    bool isGood(char c1, char c2){
        if(0<=c1-'a')   return c1-c2!='a'-'A';// c1 is lower case 
        else    return c2-c1!='a'-'A';// c1 is upper case
    }
};