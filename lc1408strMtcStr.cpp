/*
1408. String Matching in an Array

Ranking of Weekly Contest 184  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
6182 / 13661	zhongzeng 	12	1:38:41	 0:19:07  2	 1:23:41	 0:46:00  1

Company	Amazon
Related Topics	String

Test Cases:
["mass","as","hero","superhero"]
["leetcode","et","code"]
["blue","green","bu"]
["leetcoder","leetcode","od","hamlet","am"]

Runtime: 20 ms
Memory Usage: 8.4 MB
*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // brute force; words unique 
        vector<string> vec_str;
        for( int i=0; i<words.size(); i++){
            for( int j=0; j<words.size(); j++){
                if(i!=j&&isSubString(words[j],words[i])){
                    vec_str.push_back(words[i]);
                    break;
                }
            }
        }
        return vec_str;
    }
    
protected:
    bool isSubString(string & s1, string & s2){// is s2 a substing of s1
        for( int i=0; i<s1.size(); i++){
            if(s1.size()-i<s2.size())   return false;
            int j;
            for( j=0; j<s2.size(); j++){
                if(s1[i+j]!=s2[j])  break;
            }
            if(j==s2.size())    return true;
        }
        return false;
    }
};