/*
1342. Number of Steps to Reduce a Number to Zero

Company	HRT
Related Topics	Bit Manipulation

Test Cases:
14
8
123

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Number of Steps to Reduce a Number to Zero.

Next challenges:
Number Complement, IP to CIDR, Maximum Score Words Formed by Letters
*/

class Solution {
public:
    int numberOfSteps (int num) {
        int step=0;
        for( int t=num; 0<t; step++){
            if(t%2==1)  t--;
            else    t=t>>1;
        }
        return step;
    }
};