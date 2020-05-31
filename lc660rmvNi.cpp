/*
660. Remove 9

Companeis	Google, Houzz
Related Topics	Math

Test Cases:
800000000
134
10
9

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove 9.
Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Remove 9.
Next challenges: Prime Palindrome, Sum of Subsequence Widths, Divide Array Into Increasing Sequences

This can also solved by DP, recording # of 9-removed integers for each number of digits. 
*/

class Solution {
public:
    int newInteger(int n) {
        // nine-cimal; O(log(n)) time, O(1) space 
        int rv=0;
        for( int ten=1; 0<n; n/=9, ten*=10) rv=rv+n%9*ten;
        return rv;
    }
};