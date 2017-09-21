
/*
Leetcode 319. Bulb Switcher

Related Topics 
Math, Brainteaser 
Similar Questions 
Bulb Switcher II

Runtime: 3 ms
You are here! 
Your runtime beats 4.82 % of cpp submissions.

*/

class Solution {
public:
    int bulbSwitch(int n) {
        // use DP approach: if the added number has odd number of factors, returnValue++ 
        // only perfect square number has odd number of factors
        // so return the square root of n
        int lo=0, mid=(n+1)/2, hi=n+1;
        while( lo + 1 < hi ){
            if ( n / mid < mid ) {
                hi = mid;
            }else{
                lo = mid;
            }
            mid = lo + (hi-lo) /2 ;
        }
        return mid;
        // return sqrt(n); // Also 3 ms runtime
    }
};
