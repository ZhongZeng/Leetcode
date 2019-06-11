/*
1056. Confusing Number

Companies	Google
Related Topics	Math
Similar Questions	Strobogrammatic Number

Test Cases:
6
89
11
25

Next challenges: Fraction to Recurring Decimal, 
Three Equal Parts, Least Operators to Express Number

Runtime: 0 ms
Memory Usage: 8.1 MB
*/

class Solution {
public:
    bool confusingNumber(int N) {
        // N in [0,10^9]
        int m=0;
        for( int n=N; 0<n; n/=10){
            int d=n%10;
            if(d==0)    m=m*10;
            else if(d==1)   m=m*10+1;
            else if(d==8)   m=m*10+8;
            else if(d==6)   m=m*10+9;
            else if(d==9)   m=m*10+6;
            else    return false;
        }
        return N!=m;
    }
};