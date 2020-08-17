/*
1551. Minimum Operations to Make Array Equal

Medium
Companies	Brillio
Related Topics	Math

Test Cases:
3
6

Runtime: 0 ms
Memory Usage: 5.9 MB
*/

class Solution {
public:
    int minOperations(int n) {
        // O(1) time&sapce; math; 1, 3, ..., 2*i+1 (i==n-1); target=i+1; i, i-2, ..., 1 or 0
        return n%2==0?n*n/4:(n-1)*(n+1)/4;
    }
};