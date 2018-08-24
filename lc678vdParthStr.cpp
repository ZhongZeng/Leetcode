

/*
Leetcode 678. Valid Parenthesis String

Companies   
Amazon, Facebook 
Related Topics 
String
Similar Questions 
Special Binary String

Test Cases:
"()"
"((()))()(())(*()()())**(())()()()()((*()*))((*()*)"
"*("

Next challenges: Special Binary String

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    bool checkValidString(string s) {
        // inspired by O(1) space&O(n) time in Discuss; O(n) time, 2 passes, O(1) space
        int p=0, a=0;
        
        for( int i=0; i<s.size(); i++){
            switch(s[i]){
                case '(': a++;
                    break;
                case ')':
                    if(a<1){
                        if(0<p) p--;
                        else    return false;
                    }else{
                        a--;
                    }
                    break;
                case '*': a++;
                    break;
            }
        }
        
        p=a=0;
        for( int i=s.size()-1; -1<i; i--){
            switch(s[i]){
                case '(': 
                    if(a<1){
                        if(0<p) p--;
                        else    return false;
                    }else{
                        a--;
                    }
                    break;
                case ')':
                    a++;
                    break;
                case '*': a++;
                    break;
            }
        }        
        
        return true;
    }
};
