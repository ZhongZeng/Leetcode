/*
1411. Number of Ways to Paint N × 3 Grid

Companies	Hackerrank
Related Topics	Dynamic Programming

Test Cases:
1
2
3
7
5000

Runtime: 20 ms	Your runtime beats 66.67 % of cpp submissions.
Memory Usage: 8.3 MB

You can do %1000000007 with every addition to avoid using long, but I'm just lazy. 

https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/575004/dp-9-line-c-on-time-o1-space/500512
We only care about whether the color is ABA or ABC. ABA and ABC mean the pattern of the colors. For example, ABA means RedGreenRed, RedYellowRed, GYG, GRG, YRY, YGY, while ABC means RGY, RYG, YGR, and etc.  

Whether A is Red or Yellow or Green doesn't matter. We only count the permutation for ABA and ABC.

The transition function is ABA = ABA * 3 + ABC * 2; ABC = ABA * 2 + ABC * 2. If the previous row is ABA, the next row has 3 permutations of ABA patterns (BAB, BCB, and CAC) and 2 permutations of ABC patterns (BAC and CAB). Thus, 3 * ABA should be added to the right-hand-side of ABA = , 2 * ABC should be added to right-hand-side of ABC =. Similar logic applies to ABC pattern.
*/

class Solution {
public:
    int numOfWays(int n) {
        // DP, O(n) time
        vector<long> counts={6,6};// ABA & ABC; RYR,RYG,RGR,RGY,YRY,YRG,YGY,YGR,GRG,GRY,GYG,GYR
        for( int i=1; i<n; i++)
            counts={(counts[0]*3+counts[1]*2)%1000000007,(counts[0]*2+counts[1]*2)%1000000007};
        return (counts[0]+counts[1])%1000000007;
    }
};