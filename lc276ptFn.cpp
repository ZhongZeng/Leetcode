
/*
Leetcode 276. Paint Fence

Companies 
Google
Related Topics 
Dynamic Programming
Similar Questions 
House Robber, House Robber II, Paint House, Paint House II

Next challenges: Palindrome Partitioning II, 
Remove Boxes, Maximum Length of Repeated Subarray

Test Cases:
0
1
3
2
6
3
2
2

Runtime: 3 ms
Your runtime beats 2.49 % of cpp submissions.

*/

class Solution {
public:
    int numWays(int n, int k) {
        // no more than two adjacent fence posts have the same color
        if(n<1) return 0;
        else if(n<2)    return k;
        else if(n<3)    return k*k;
        
        if(k<1) return 0;
        else if(k<2)    return n<3?k:0;
        
        int ms=k, md=k*(k-1), t;// last 2 diff, last 2 same
        for(int i=2; i<n; i++){
            t=(md+ms)*(k-1);
            ms=md;
            md=t;
        }
        
        return ms+md;
    }
};
