/*
908. Smallest Range I

Companies	Adobe
Related Topics	Math

Test Cases:
[1]
0
[0,10]
2
[1,3,6]
3

Runtime: 20 ms	Your runtime beats 92.30 % of cpp submissions.
Memory Usage: 9.7 MB	Your memory usage beats 54.52 % of cpp submissions.
*/

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        /// array, brainteaser
        int mx=A[0], mn=A[0];
        for( int i=1; i<A.size(); i++){
            if(mx<A[i]) mx=A[i];
            else if(A[i]<mn)    mn=A[i];
        }
        return mx-mn-2*K<0?0:mx-mn-2*K;
    }
};