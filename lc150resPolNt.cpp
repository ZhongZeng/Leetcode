

/*

Leetcode 150. Evaluate Reverse Polish Notation

Related Topics 
Stack 
Similar Questions 
Basic Calculator, Expression Add Operators

Next challenges: Basic CalculatorExpression Add Operators

Test Cases:
["18"]
["2", "1", "+", "3", "*"]
["4", "13", "5", "/", "+"]
["3","-4","+"]
["+3","-4","+"]

Runtime: 10 ms
Your runtime beats 31.24 % of cpp submissions.

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Valid operators are +, -, *, /. Each operand may be an integer or another expression.
        // stoi() used; shouldn't be hard to write one yourself. 
		// This should be Easy. Just be careful of cases of negative numbers. 
        if(tokens.size()<1) return 0;
        vector<int> vc;
        for(int i=0, t; i<tokens.size(); i++){
            
            switch(tokens[i][0]){
                case '+':
                    if(tokens[i].size()<2){
                        t=vc[vc.size()-2]+vc.back();
                        vc.pop_back();
                        vc.back()=t;
                    }else{
                        vc.push_back(stoi(tokens[i].substr(1,tokens[i].size()-1)));
                    }
                    break;
                case '-': 
                    if(tokens[i].size()<2){
                        t=vc[vc.size()-2]-vc.back();
                        vc.pop_back();
                        vc.back()=t;
                    }else{
                        vc.push_back(stoi(tokens[i]));
                    }
                    break;
                case '*': t=vc[vc.size()-2]*vc.back();
                    vc.pop_back();
                    vc.back()=t;
                    break;
                case '/': t=vc[vc.size()-2]/vc.back();
                    vc.pop_back();
                    vc.back()=t;
                    break;
                default: vc.push_back(stoi(tokens[i]));
                    break;
            }
        }
        
        return vc[0];
    }
    
};