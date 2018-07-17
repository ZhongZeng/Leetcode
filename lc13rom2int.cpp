
/*
Leetcode 13. Roman to Integer

Companies 
Facebook, Microsoft, Bloomberg, Uber, Yahoo
Related Topics 
Math, String 
Similar Questions 
Integer to Roman

Test Cases:
"III"
"IV"
"IX"
"LVIII"
"MCMXCIV"

Next challenges: Integer to Roman

Runtime: 48 ms
Your runtime beats 97.63 % of cpp submissions.

*/

class Solution {
public:
    int romanToInt(string s) {
        // I:1, V:5, X:10, L:50, C:100, D:500, M:1000
        // I only b/f V(5), X(10): 4, 9; X only b/f L(50), C(100): 40 and 90; C only b/f D(500), M (1000): 400, 900 
        int rt=0;
    
        for( int i=0; i<s.size(); i++){
            switch(s[i]){
                case 'I':
                    if(i+1<s.size()){
                        if(s[i+1]=='V'){
                            rt+=4;
                            i++;
                        }else if(s[i+1]=='X'){
                            rt+=9;
                            i++;
                        }else{
                            rt+=1;
                        }
                    }else{
                        rt+=1;
                    }
                    break;
                case 'V':
                    rt+=5;
                    break;
                case 'X':
                    if(i+1<s.size()){
                        if(s[i+1]=='L'){
                            rt+=40;
                            i++;
                        }else if(s[i+1]=='C'){
                            rt+=90;
                            i++;
                        }else{
                            rt+=10;
                        }
                    }else{
                        rt+=10;
                    }
                    break;
                case 'L':
                    rt+=50;
                    break;
                case 'C':
                    if(i+1<s.size()){
                        if(s[i+1]=='D'){
                            rt+=400;
                            i++;
                        }else if(s[i+1]=='M'){
                            rt+=900;
                            i++;
                        }else{
                            rt+=100;
                        }
                    }else{
                        rt+=100;
                    }
                    break;
                case 'D':
                    rt+=500;
                    break;
                case 'M':
                    rt+=1000;
                    break;                    
            }
        }
    
        return rt;
    }
};
