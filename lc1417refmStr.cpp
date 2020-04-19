/*
1417. Reformat The String

Ranking of Weekly Contest 185  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
2031 / 9206	zhongzeng 	12	1:26:10	 0:19:29	 1:26:10	 0:33:33

Companies	Microsoft
Related Topics	String

Test Cases:
"a0b1c2"
"leetcode"
"1229857369"
"covid2019"
"ab123"

Runtime: 16 ms	Your runtime beats 54.55 % of cpp submissions.
Memory Usage: 7.2 MB
*/

class Solution {
public:
    string reformat(string s) {
        // O(n) time, O(1) space
        int l=0, d=0;
        string t;
        
        for( int i=0; i<s.size(); i++){
            if(isLetter(s[i]))  l++;
            else    d++;
        }
        
        if(l==d+1){
            for( int i=-1, j=-1; t.size()<s.size(); ){
                if(t.size()%2==0){
                    while( isDigit(s[++j]) ){}
                    t.push_back(s[j]);
                }else{
                    while( isLetter(s[++i]) ){}
                    t.push_back(s[i]);
                }
            }
        }else if(d==l+1||d==l){
            for( int i=-1, j=-1; t.size()<s.size(); ){
                if(t.size()%2==1){
                    while( isDigit(s[++j]) ){}
                    t.push_back(s[j]);
                }else{
                    while( isLetter(s[++i]) ){}
                    t.push_back(s[i]);
                }
            }
        }else{
            return "";
        }
        
        return t;
    }
    
protected:
    bool isLetter(char c){
        int l=c-'a';
        return -1<l&&l<26;
    }
    
    bool isDigit(char c){
        int l=c-'0';
        return -1<l&&l<10;
    }
};