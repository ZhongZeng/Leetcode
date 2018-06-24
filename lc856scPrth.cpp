
/*

Leetcode 856. Score of Parentheses

Suggested Tag: Stack 

Test Cases:
"()"
"(())"
"()()"
"(()(()))"
"()(())"

Runtime: 4 ms

*/

class Solution {
public:
    int scoreOfParentheses(string S) {
        // stack, O(n) time
        int sum=0, t;
        vector<int> vc;
        
        for( int i=0; i<S.size(); i++ ){
            if(S[i]=='('){
                vc.push_back(0);
            }else{
                if(vc.back()==0){
                    vc.back()=1;
                }else{
                    t=0;
                    while(0<vc.size()&&vc[vc.size()-1]!=0){
                        t+=vc.back();
                        vc.pop_back();
                    }   
                    
                    vc.back()=t<<1;
                }
                
                while(1<vc.size()&&vc[vc.size()-2]!=0){
                    t=vc.back();
                    vc.pop_back();
                    vc.back()+=t;
                }                 
            }
        }
        
        return vc[0];
    }
};
