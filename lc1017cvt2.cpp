/*
1017. Convert to Base -2

Test Cases:
0
2
3
4

Companies	Airbnb
Related Topics	Math

Runtime: 4 ms
Memory Usage: 8.2 MB

*/

class Solution {
public:
    string baseNeg2(int N) {
        // math, divide continuously; N in [0,10^9] 
        if(N==0)    return "0";
        string rt;
        int n, b;
        
        for( n=N, b=true; 0<n; b=!b){
            rt.push_back(n%2==0?'0':'1');
            if(b)   n=n>>1;// n>0
            else    n=(n+1)>>1; // n<0
        }
        
        reverse(rt.begin(), rt.end());
        
        return rt;
    }
};