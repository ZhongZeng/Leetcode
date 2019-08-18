/*
1160. Find Words That Can Be Formed by Characters

Ranking of Weekly Contest 150  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
1179 / 5338	zhongzeng 	12	0:57:31	 0:10:07	 0:19:59	 0:47:31  2	

Test Cases:
["cat","bt","hat","tree"]
"atach"
["hello","world","leetcode"]
"welldonehoneyr"

Runtime: 72 ms	Your runtime beats 85.71 % of cpp submissions.
Memory Usage: 20 MB
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum=0;
        vector<int> p(26,0);
        for( int i=0; i<chars.size(); i++)  p[chars[i]-'a']+=1;
        for( int i=0; i<words.size(); i++)  sum+=isGood( words[i], p);
        return sum;
    }
    
    int isGood(string & s, vector<int> p){
        for( int i=0; i<s.size(); i++){
            p[s[i]-'a']-=1;
            if(p[s[i]-'a']<0)   return 0;
        }
        return s.size();
    }
};