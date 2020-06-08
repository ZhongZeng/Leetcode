/*
1447. Simplified Fractions

Medium
Companies	Google
Related Topics	Math

Test Cases:
6
2
4

Runtime: 148 ms, faster than 68.46% of C++ online submissions for Simplified Fractions.
Memory Usage: 22.4 MB, less than 35.72% of C++ online submissions for Simplified Fractions.
Next challenges: Split Array With Same Average, Three Equal Parts,
Reverse Subarray To Maximize Array Value
*/

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        // Easy; n in [1,100]
        vector<string> nums, strs;
        for( int i=0; i<=n; i++){
            string num;
            for( int j=i; 0<j; j=j/10)  num.push_back(j%10+'0');
            reverse( num.begin(), num.end());
            nums.push_back(num);
        }
        
        for( int i=2; i<=n; i++){
            for( int j=1; j<i; j++){
                if(!hasCommonFactor(j, i)){
                    string str;
                    str.append(nums[j]);
                    str.push_back('/');
                    str.append(nums[i]);
                    strs.push_back(str);
                }
            }
        }
        
        return strs;
    }
    
protected:
    bool hasCommonFactor( int a, int b){// a<b
        while(1<a){
            if(b%a==0)  return true;
            int c=b%a;
            b=a;
            a=c;
        }
        return false;
    }
};