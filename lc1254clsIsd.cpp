/*
1254. Number of Closed Islands

Medium
Companeis	Google, Amazon
Related Topics	Depth-first Search

Test Cases:
[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
[[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
[[1,1,1,1,1,1,1],[1,0,0,0,0,0,1],[1,0,1,1,1,0,1],[1,0,1,0,1,0,1],[1,0,1,1,1,0,1],[1,0,0,0,0,0,1],[1,1,1,1,1,1,1]]

Runtime: 20 ms, faster than 72.80% of C++ online submissions for Number of Closed Islands.
Memory Usage: 9.6 MB, less than 56.63% of C++ online submissions for Number of Closed Islands.
Next challenges: Sort Items by Groups Respecting Dependencies,
Maximum Product of Splitted Binary Tree, Find All the Lonely Nodes
*/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // O(m*n) time
        if(grid.size()<1||grid[0].size()<1) return 0;
        int sum=0;
        for( int i=0; i<grid.size(); i++)   dfs( i, 0, -1, grid);
        for( int i=0; i<grid.size(); i++)   dfs( i, grid[0].size()-1, -1, grid);
        for( int j=0; j<grid[0].size(); j++)    dfs( 0, j, -1, grid);
        for( int j=0; j<grid[0].size(); j++)    dfs( grid.size()-1, j, -1, grid);
        
        for( int i=0; i<grid.size(); i++){
            for( int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==0){
                    sum++;
                    dfs( i, j, -1, grid);
                }
            }
        }
        
        return sum;
    }
    
protected:
    void dfs( int i, int j, int num, vector<vector<int>>& grid){
        if(i<0||grid.size()<=i||j<0||grid[i].size()<=j||grid[i][j]!=0)  return ;
        grid[i][j]=num;
        dfs( i+1, j, num, grid);
        dfs( i-1, j, num, grid);
        dfs( i, j+1, num, grid);
        dfs( i, j-1, num, grid);
        return ;
    }
};