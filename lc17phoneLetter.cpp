
/*
Leetcode 17. Letter Combinations of a Phone Number

Tags: Backtracking, String
Similar Problems: (M) Generate Parentheses (M) Combination Sum (E) Binary Watch
Next challenges: (M) Generate Parentheses(M) Combination Sum(E) Binary Watch

You are here! 
Your runtime beats 2.09 % of cpp submissions.	3 ms

Others' solutions solve this problem using a different approach, not backtracking. 

Test Cases:
""
"9"
"23"

*/


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // string is a vector of char
        // assuming no 0s
        vector<string> vs;
        if(digits.size()==0) return vs;
        string s(digits.size(),'a');
        vector<char> pk= {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
        // phone keyboard table 4*7 and 4*9
        int i=0;
        while( i!=-1 ){ // 'z'+1=='{'
            // cout<<s<<endl;
            /* track if s satisfies the condition*/
            i=-1;
            while( ++i != s.size() ){
                if( pk[s[i]-'a'] != digits[i]){
                    break;
                }
            }
            if( i==s.size()){
                vs.push_back(s);
                i--;
            }
            
            /* generate the next string s*/
            while( i!= -1){
                if(s[i]!='z'){
                    s[i]+=1;
                    break;
                }else{
                    s[i]='a';
                    i--;
                }
            }
            
        }
        
        return vs;
    }
};
