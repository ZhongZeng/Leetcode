/*
1582. Special Positions in a Binary Matrix

Easy
Companies	Google
Related Topics	Array

Test Cases:
[[1,0,0],[0,0,1],[1,0,0]]
[[1,0,0],[0,1,0],[0,0,1]]
[[0,0,0,1],[1,0,0,0],[0,1,1,0],[0,0,0,0]]
[[0,0,0,0,0],[1,0,0,0,0],[0,1,0,0,0],[0,0,1,0,0],[0,0,0,1,1]]

Runtime: 56 ms	Your runtime beats 46.22 % of cpp submissions.
Memory Usage: 13 MB	Your memory usage beats 81.25 % of cpp submissions.
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // O(m*n) time, O(n+m) space
        if(mat.size()<1||mat[0].size()<1)   return 0;
        int sum=0;
        vector<int> rows, cols;
        
        for( int i=0, count=0; i<mat.size(); i++, count=0){
            for( int j=0; j<mat[i].size(); j++){
                if(mat[i][j]==1){
                    count++;
                    if(1<count) break;
                }
            }
            rows.push_back(count);
        }
        for( int j=0, count=0; j<mat[0].size(); j++, count=0){
            for( int i=0; i<mat.size(); i++){
                if(mat[i][j]==1){
                    count++;
                    if(1<count) break;
                }
            }
            cols.push_back(count);
        }
        
        for( int i=0; i<mat.size(); i++){
            for( int j=0; j<mat[i].size(); j++){
                if(mat[i][j]==1&&rows[i]==1&&cols[j]==1)
                    sum++;
            }
        }
        return sum;
    }
};