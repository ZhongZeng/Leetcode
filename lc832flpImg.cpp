
/*
Leetcode 832. Flipping an Image

Companies
Google

Related Topics
Array

Next challenges: Word Ladder II, My Calendar II, Number of Subarrays with Bounded Maximum

Test Case:
[[1,1,0],[1,0,1],[0,0,0]]

Runtime: 15 ms

*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int i, j, k, t;
        for( i=0; i<A.size(); i++){//reverse
            for( j=0, k=A[0].size()-1, t; j<k; j++, k--){
                t=A[i][j]!=1;
                A[i][j]=A[i][k]!=1;
                A[i][k]=t;
            }
            if(j==k)    A[i][j]=A[i][j]!=1;
        }
            
        return A;
    }
};
