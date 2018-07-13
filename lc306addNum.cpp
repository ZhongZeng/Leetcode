
/*
Leetcode 306. Additive Number

Companies 
Epic Systems
Related Topics 
Backtracking
Similar Questions 
Split Array into Fibonacci Sequence

Test Cases:
"1203"
"00000"
"101"
"112358"
"199100199"
"1023"
"0"
"123"
"124"

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

Next challenges: Split Array into Fibonacci Sequence

*/

class Solution {
public:
    bool isAdditiveNumber(string num) {// corner case '0'
        if(num.size()<3)    return false;
        if(num[0]=='0'){// "00..." corner case 
            int i=0;
            for( ; i<num.size(); i++)   if(num[i]!='0') break;
            if(i==num.size())   return true;
        }
        
        int len=num[0]!='0'?num.size()-2:1;// "0#..."
        long a=0, b;
        
        for( int i=0; i<len; i++){
            a=a*10+num[i]-'0';
            b=0;
            if(num[i+1]!='0'){// b doesn't start with '0' 
                for( int j=i+1; j<num.size()-1; j++){
                    b=b*10+num[j]-'0';
                    
                    if(backTrack( a, b, j+1, num))  return true;
                }
            }else{// b==0
                if(backTrack( a, 0, i+2, num))  return true;
            }
        }
        
        return false;
    }
    
    bool backTrack( long a, long b, int j, string& num ){// no 0 for b or c or non-1st a
        if(num[j]=='0') return false;
        long c=0, t=a+b;
        
        for( int i=j; i<num.size(); i++){
            c=c*10+num[i]-'0';
            if(t==c){
                a=b;
                b=c;
                c=0;
                t=a+b;
                
                if(i+1<num.size()){
                    if(num[i+1]=='0')   return false;
                }else{
                    return true;
                }
            }else if(t<c){
                return false;
            }
        }
        
        return false;
    }
};
