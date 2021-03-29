/*
1621. Number of Sets of K Non-Overlapping Line Segments
Medium

Companies:	Amazon
Related Topics:	Dynamic Programming

Runtime: 72 ms	Your runtime beats 70.00 % of cpp submissions.
Memory Usage: 100.3 MB	Your memory usage beats 7.37 % of cpp submissions.
*/

class Solution {
public:
    int numberOfSets(int n, int k) {
        // O(n*k) time, O(n) space; O(k) space possible; Dynamic Programming 
        // n points, k segments; k in [1,n-1] 
        vector<long> nums0(n+1, 1);// ignore all values @index 0
        for( int i=1; i<=k; i++){// i segments 
            vector<long> nums1={0, 0};
            for( long j=2, sum=0; j<=n; j++){// j points
                sum+=nums0[j-1];
                nums1.push_back(
                    (
                        sum/*last segment is [[1,j-1], j], sum of numberOfSets( [1,j-1], i-1)*/
                        +
                        nums1.back()/*last segment not includes j'th point, numberOfSets( j-1, i)*/
                    )%1000000007);
            }
            nums0=nums1;
        }
        return nums0.back();
    }
};