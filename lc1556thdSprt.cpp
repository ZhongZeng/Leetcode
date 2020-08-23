/*
1556. Thousand Separator

Easy

Related Topcis	string

Runtime: 4 ms, faster than 20.00% of C++ online submissions for Thousand Separator.
Memory Usage: 5.9 MB, less than 80.00% of C++ online submissions for Thousand Separator.
Next challenges: Mini Parser, Remove Palindromic Subsequences, Making File Names Unique
*/

class Solution {
public:
    string thousandSeparator(int n) {
        if(n==0)    return "0";
        string s;
        for( int m=n, t=0; 0<m; m=m/10, t=t<2?t+1:0){
            s.push_back((char)('0'+m%10));
            if(t==2&&9<m)   s.push_back('.');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};