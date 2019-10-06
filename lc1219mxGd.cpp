/*
1219. Path with Maximum Gold

Companies	Google
Related Topics	Backtracking 

Test Cases:
[[0,6,0],[5,8,7],[0,9,0]]
[[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]

Runtime: 48 ms	Your runtime beats 83.33 % of cpp submissions.
Memory Usage: 8.7 MB
*/

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        // DFS, O(4**(m*n) time), O(m*n) space; 1 <= grid.length, grid[i].length <= 15
        int mx=0;
        for( int i=0; i<grid.size(); i++){
            for( int j=0; j<grid[0].size(); j++){
                maxGold( grid, i, j, 0, mx);
            }
        }
        return mx;
    }
    
protected:
    void maxGold( vector<vector<int>>& grid, int r, int c, int ct, int& mx){
        if(r<0||c<0||grid.size()<=r||grid[r].size()<=c||grid[r][c]<=0)  return;
        
        ct+=grid[r][c];
        mx=mx<ct?ct:mx;
        grid[r][c]=-grid[r][c];

        maxGold( grid, r-1, c, ct, mx);
        maxGold( grid, r+1, c, ct, mx);
        maxGold( grid, r, c-1, ct, mx);
        maxGold( grid, r, c+1, ct, mx);
        
        grid[r][c]=-grid[r][c];
        
        return ;
    }
};