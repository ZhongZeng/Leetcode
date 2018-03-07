
/*
Leetcode 246. Strobogrammatic Number

Companies 
Google 
Related Topics 
Hash Table, Math
Similar Questions 
Strobogrammatic Number II, Strobogrammatic Number III

Next challenges: Strobogrammatic Number II, Strobogrammatic Number III

Test Cases:
"1"
"1691"
"121"
"10"

Runtime: 2 ms
Your runtime beats 12.39 % of cpp submissions.

*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        // 6-9,0,1,8 
        // the number rotated 180 not each digit
        int i, j;
        for( i=0, j=num.size()-1; i<=j; i++, j--){
            switch(num[i]){
                case '0': if(num[j]!='0')   return false;
                    break;
                case '1': if(num[j]!='1')   return false;
                    break;
                case '8': if(num[j]!='8')   return false;
                    break;
                case '6': if(num[j]!='9')   return false;
                    break;
                case '9': if(num[j]!='6')   return false;
                    break;
                default:
                    return false;
            }
        }
        
        return true;
    }
};
