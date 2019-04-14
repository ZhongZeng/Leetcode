/*
1021. Remove Outermost Parentheses

Companies	Google
Related Topics	Stack

Test Cases:
"(()())(())"
"(()())(())(()(()))"
"()()"

Runtime: 16 ms
Memory Usage: 9.3 MB
Your runtime beats 15.07 % of cpp submissions.

Next challenges: Basic Calculator, 
Closest Binary Search Tree Value II, Remove Duplicate Letters

*/

class Solution {
public:
    string removeOuterParentheses(string S) {
        if(S.size()<1)  return S;
        vector<int> vc;
        string rt;
        
        for( int i=0, t=0; i<S.size(); i++){
            if(S[i]=='('){
                t++;
            }else{// ')'
                t--;
                if(t==0)    vc.push_back(i);
            }
        }
        
        for( int i=1, j=0; i<S.size(); i++){// S[0]=='(' guranteed 
            if(i==vc[j]){
                i++;
                j++;
            }else{
                rt.push_back(S[i]);
            }
        }
        
        return rt;
    }
};