
/*

Leetcode 766. Toeplitz Matrix



Test Cases:
[[1,2,3,4],[5,1,2,3],[9,5,1,2]]
[[1,2],[5,1],[9,5]]
[[1,2],[2,2]]

Runtime: 18 ms

*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		// O(m*n) time 
        if(matrix.size()<1) return true;
        if(matrix[0].size()<1) return true;
        int x;
        
        for(int i=0; i<matrix[0].size(); i++){
            x=matrix[0][i];
            for(int j=0; j<matrix.size()&&i+j<matrix[0].size(); j++){
                if(matrix[j][i+j]!=x)   return false;
            }
        }
        
        for(int i=0; i<matrix.size(); i++){
            x=matrix[i][0];
            for(int j=0; i+j<matrix.size()&&j<matrix[0].size(); j++){
                if(matrix[i+j][j]!=x)   return false;
            }
        }        
        
        return true;
    }
};
