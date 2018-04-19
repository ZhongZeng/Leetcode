
/*
Leetcode 439. Ternary Expression Parser

Companies 
Snapchat 
Related Topics 
Stack, Depth-first Search 
Similar Questions 
Mini Parser, Remove Comments, Parse Lisp Expression

Next challenges: Mini ParserParse Lisp Expression

Test Cases:
"T?2:3"
"F?1:T?4:5"
"T?T?F:5:3"

Runtime: 8 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    string parseTernary(string expression) {
        // Stack, O(n) time 
        // 0-9 must be followed by ':'
        // consists of digits 0-9, ?, :, T and F(F could be returned)
        if(expression.size()<1) return "";
        int qs=0;
        string tf, tp;
        tf.push_back(expression[0]);
        if(tf.back()=='F')  qs=1;
        
        for(int i=2; i<expression.size(); i++){
            if(tf.back()=='F'){
                if(expression[i]=='?'){
                    qs++;
                }else if(expression[i]==':'){
                    qs--;
                    if(qs==0)   tf.pop_back();
                }
            }else{
                if(i+1<expression.size()&&expression[i+1]=='?'){
                    tf.push_back(expression[i++]);
                    if(tf.back()=='F')  qs=1;
                }else if(expression[i]==':'){
                    return tp;
                }else{
                    if(tf.back()!='F')  tp.push_back(expression[i]);
                }                
            }
        }
        
        return tp;
    }
};