/*
1035. Uncrossed Lines

Company	Amazon
Related Topics	Array

Test Cases:
[1,4,2]
[1,2,4]
[2,5,1,2,5]
[10,5,2,1,5,2]
[1,3,7,1,7,5]
[1,9,2,5,1]

Runtime: 20 ms, faster than 36.38% of C++ online submissions for Uncrossed Lines.
Memory Usage: 13.1 MB, less than 9.09% of C++ online submissions for Uncrossed Lines.
Next challenges:
Maximum Sum Circular Subarray
Sort the Matrix Diagonally
Find the Distance Value Between Two Arrays

https://leetcode.com/problems/uncrossed-lines/discuss/652032/C%2B%2B-Dynamic-Programming-O(m*n)-TimeandSpace
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        // Dynamic Programming, Geometric; O(m*n) time&space
        // uncross == match A[i,) with B[j,), i&j as last match positions in A&B; similar to Longest Common Sequence
        vector<vector<int>> mx(A.size()+1, vector<int> (B.size()+1, 0));// mx[i][j]=maxUncrossedLines for A[0,j)&B[0,j)
        for( int i=0; i<A.size(); i++){
            for( int j=0; j<B.size(); j++){
                int t=mx[i][j]+(A[i]==B[j]?1:0);
                if(t<mx[i][j+1])    t=mx[i][j+1];
                if(t<mx[i+1][j])    t=mx[i+1][j];
                mx[i+1][j+1]=t;
            }
        }
        return mx.back().back();
    }
};