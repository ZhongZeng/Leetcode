/*
1363. Largest Multiple of Three

Runtime: 12 ms, faster than 50.00% of C++ online submissions for Largest Multiple of Three.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Largest Multiple of Three.
Next challenges:
Fraction to Recurring Decimal, Stickers to Spell Word, Mirror Reflection

Test Cases:
[9,8,6,8,6]
[8,1,9]
[8,6,7,1,0]
[1]
['0','0','0','0','0']
*/

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        // O(n) time, O(1) space; easy; digits[i] in [0,9]; multiple of 3 == sum of digits divisible by 3
        string rt;
        int three=0;
        vector<int> digit_count(10,0);
        vector<char> digit_char={'0','1','2','3','4','5','6','7','8','9'};
        
        // record # & sum of digits 
        for( int i=0; i<digits.size(); i++){
            digit_count[digits[i]]+=1;
            three=(three+digits[i])%3;
        }
        
        // dividible by 3
        if(three==1){
            for( int i=1; i<digit_count.size()&&three!=0; ){// 1
                if(0<digit_count[i]){
                    digit_count[i]-=1;
                    three=(three-1+3)%3;
                }else{
                    i+=3;
                }
            }
            for( int i=2; i<digit_count.size()&&three!=0; ){// 2+2
                if(0<digit_count[i]){
                    digit_count[i]-=1;
                    three=(three-2+3)%3;
                }else{
                    i+=3;
                }
            }
        }else if(three==2){
            for( int i=2; i<digit_count.size()&&three!=0; ){// 2
                if(0<digit_count[i]){
                    digit_count[i]-=1;
                    three=(three-2+3)%3;
                }else{
                    i+=3;
                }
            }
            for( int i=1; i<digit_count.size()&&three!=0; ){// 1+1
                if(0<digit_count[i]){
                    digit_count[i]-=1;
                    three=(three-1+3)%3;
                }else{
                    i+=3;
                }
            }
        }
        if(three!=0)    return "";
        
        // construct string to return 
        for( int i=digit_count.size()-1; 0<i; i--){
            for( int j=0; j<digit_count[i]; j++) rt.push_back(digit_char[i]);
        }
        if(rt.empty())  return 0<digit_count[0]?"0":"";// no leading '0'
        for( int j=0; j<digit_count[0]; j++) rt.push_back('0');
        
        return rt;
    }
};