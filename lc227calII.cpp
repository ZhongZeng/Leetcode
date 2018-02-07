

/*
Leetcode 227. Basic Calculator II


Related Topics 
String
Similar Questions 
Basic Calculator, Expression Add Operators, Basic Calculator III

Next challenges: Basic Calculator, Expression Add Operators, Basic Calculator III

Test Cases:
"3+2*2"
"3+2*2/3"
"3+2-2+3"
"3 + 2  *2"
"3+  2*2  /3"
"3  + 2 - 2 + 3"
"2/3*2"

Runtime: 14 ms
Your runtime beats 53.16 % of cpp submissions.

*/

class Solution {
public:
    int calculate(string s) {
        // The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
        // O(n) time; O(1) space, vc.size()<6, 1+2*3 or 1+2  or 1
        if(s.size()<1)  return 0;
        vector<int> vc;
        int e=0;
        for(int i=0, j=0; i<s.size(); i++){
            switch(s[i]){
                case '+':
                    vc.push_back(e);
                    opl(vc);
                    vc.push_back(-1);
                    e=0;
                    break;
                case '-':
                    vc.push_back(e);
                    opl(vc);
                    vc.push_back(-2);
                    e=0;
                    break;
                case '*':
                    vc.push_back(e);
                    opm(vc);
                    vc.push_back(-3);
                    e=0;
                    break;
                case '/':
                    vc.push_back(e);
                    opm(vc);
                    vc.push_back(-4);
                    e=0;                    
                    break;
                case ' ':// ignore space
                    break;
                default:// number
                    e=e*10+s[i]-'0';
            }
        }
        
        vc.push_back(e);
        opl(vc);
        
        return vc[0];
    }
    
    void opl(vector<int>& vc){
        while(2<vc.size()){
            switch(vc[vc.size()-2]){
                case -1: vc[vc.size()-3]+=vc.back();
                    break;
                case -2: vc[vc.size()-3]-=vc.back();
                    break;
                case -3: vc[vc.size()-3]*=vc.back();
                    break;
                case -4: vc[vc.size()-3]/=vc.back();
                    break;
            }
            vc.pop_back();
            vc.pop_back();
        }
        return ;
    }
    
    void opm(vector<int>& vc){
        bool t=true;
        while(2<vc.size()&&t){
            switch(vc[vc.size()-2]){
                case -1: t=false;
                    break;
                case -2: t=false;
                    break;
                case -3: vc[vc.size()-3]*=vc.back();vc.pop_back();vc.pop_back();
                    break;
                case -4: vc[vc.size()-3]/=vc.back();vc.pop_back();vc.pop_back();
                    break;
            }
        }
        return ;
    }    
    
};