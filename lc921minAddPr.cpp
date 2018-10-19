
/*
Leetcode 921. Minimum Add to Make Parentheses Valid

Test Cases:
"())"
"((("
"()"
"()))(("

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

Next challenges: Palindrome Permutation II, Stickers to Spell Word, Construct Quad Tree

*/

class Solution {
public:
    int minAddToMakeValid(string S) {
        // stack
        int rt=0, pr=0;
        
        for( int i=0; i<S.size(); i++){
            if(S[i]=='('){
                pr++;
            }else{
                if(0<pr)     pr--;
                else    rt++;
            }
        }
        rt+=pr;
        
        return rt;
    }
};
