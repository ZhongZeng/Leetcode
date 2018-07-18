
/*
Leetcode 12. Integer to Roman

Companies 
Twitter 
Related Topics 
Math, String 
Similar Questions 
Roman to Integer, Integer to English Words

Test Cases:
3
4
9
58
1994

Next challenges: Word Ladder II, Repeated Substring Pattern, Add Bold Tag in String

Runtime: 40 ms
Your runtime beats 99.68 % of cpp submissions.

*/

class Solution {
public:
    string intToRoman(int num) {
        // I only b/f V(5), X(10): 4, 9; X only b/f L(50), C(100): 40 and 90; C only b/f D(500), M (1000): 400, 900 
        // num in [1,3999]
        int t, i=0;
        char c;
        string rt;
        vector<char> vc={'I','V','X','L','C','D','M'};// 1, 5, 10, 100, 500, 1000
        
        while(num!=0){
            t=num%10;
            num=num/10;
            
            switch(t){
                case 1: rt.push_back(vc[2*i]);
                    break;
                case 2:
                    rt.push_back(vc[2*i]);
                    rt.push_back(vc[2*i]);
                    break;
                case 3:
                    rt.push_back(vc[2*i]);
                    rt.push_back(vc[2*i]);
                    rt.push_back(vc[2*i]);
                    break;
                case 4:
                    rt.push_back(vc[2*i+1]);
                    rt.push_back(vc[2*i]);
                    break;
                case 5: rt.push_back(vc[2*i+1]);
                    break;
                case 6: 
                    rt.push_back(vc[2*i]);
                    rt.push_back(vc[2*i+1]);
                    break;
                case 7:
                    rt.push_back(vc[2*i]);
                    rt.push_back(vc[2*i]);
                    rt.push_back(vc[2*i+1]);
                    break;
                case 8:
                    rt.push_back(vc[2*i]);
                    rt.push_back(vc[2*i]);
                    rt.push_back(vc[2*i]);
                    rt.push_back(vc[2*i+1]);
                    break;
                case 9:
                    rt.push_back(vc[2*i+2]);
                    rt.push_back(vc[2*i]);
                    break;
            }
            
            i++;
        }
        
        for( int i=0, j=rt.size()-1; i<j; i++, j--){
            c=rt[i];
            rt[i]=rt[j];
            rt[j]=c;
        }
        
        return rt;
    }
};
