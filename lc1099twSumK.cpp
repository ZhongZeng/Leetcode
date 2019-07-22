/*
1099. Two Sum Less Than K

Companies	Amazon
Related Topics	Array
Similar Questions	Two Sum, Two Sum II - Input array is sorted, 
3Sum Smaller, Subarray Product Less Than K

Test Cases:
[34,23,1,24,75,33,54,8]
60
[10,20,30]
14

Runtime: 4 ms	Your runtime beats 87.66 % of cpp submissions.
Memory Usage: 8.5 MB

Next challenges: 3Sum Smaller, Subarray Product Less Than K
Next challenges: Word Ladder II, Transform to Chessboard, Height Checker
*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        // O(n*n) is trivial
        int mn=-1, t;
        for( int i=0; i<A.size(); i++){
            for( int j=i+1; j<A.size(); j++){
                t=A[i]+A[j];
                if(mn<t&&t<K)   mn=t;
            }
        }
        return mn!=-1?mn:-1;
    }
};