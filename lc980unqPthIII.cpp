/*
980. Unique Paths III

Related Topics: Dynamic Programming, Backtracking 

Test Cases:
[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
[[0,1],[2,0]]

https://leetcode.com/contest/weekly-contest-120/ranking/1/
Weekly Contest 120:	191 / 3876

Runtime: 0 ms
*/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // post-order DFS; grid.length*grid[0].length in [1,20], if too large, need DP 
        // The tricky part of this problem is that we need to visit all non-obstacle exactly once, not zero time, not twice. We start from the starting square and do post-order DFS. For each square, the dfs() function return total number path from this square to the ending sqaure, given previous path to this square. 
		// If we've visited the square, we mark its value as 1. When we're done with all dfs() from this square, we reverse the value of the square back to 0. 
		if(grid.size()<1||grid[0].size()<1) return 0;
        int r, c, sum=grid.size()*grid[0].size();
        
        for( int i=0; i<grid.size(); i++){
            for( int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    r=i;
                    c=j;
                    grid[i][j]=0;// modifed for dfs() 
                }else if(grid[i][j]==-1){
                    sum--;
                }
            }
        }
        
        return dfs( r, c, grid, sum);
    }
    
protected:
    int dfs( int r, int c, vector<vector<int>>& grid, int sum){// -1-unvisitable, 0-unvisted, 1-visited, 2-destination
        if(r<0||grid.size()-1<r||c<0||grid[0].size()-1<c||grid[r][c]==-1||grid[r][c]==1)  return 0;// out of boundary or unvisitable or visited 
        if(grid[r][c]==2)   return sum==1?1:0;// reachs destination; check if all non-obstacle visited exactly once 
        grid[r][c]=1;// If we've visited the square, we mark its value as 1. 
        int u=dfs(r-1,c,grid,sum-1),d=dfs(r+1,c,grid,sum-1),l=dfs(r,c-1,grid,sum-1),rg=dfs(r,c+1,grid,sum-1);// r used 
        grid[r][c]=0;// When we're done with all dfs() from this square, we reverse the value of the square back to 0. 
        return u+d+l+rg;// return # ways to reach end 
    }
};