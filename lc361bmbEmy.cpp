
/*
Leetcode 361. Bomb Enemy

Companies 
Google 
Related Topics 
Dynamic Programming

Next challenges: Max Sum of Rectangle No Larger Than K, 
Freedom Trail, Out of Boundary Paths

Test Cases:
[["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
[["W"],["E"],["W"],["0"],["E"]]

Runtime: 38 ms
Your runtime beats 49.38 % of cpp submissions.

*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        // DP 
        // Note that you can only put the bomb at an empty cell. 
		// This should be Easy. 
        if(grid.size()<1||grid[0].size()<1) return 0;
        int mx=0;
        vector<int> vc(grid[0].size(), 0);
        vector<vector<int>> row(grid.size(), vc), col(grid.size(), vc);;
        
        for(int i=0; i<grid.size(); i++){
            if(grid[i][0]=='E') row[i][0]=1;
            for(int j=1; j<grid[0].size(); j++){
                if(grid[i][j]=='E') row[i][j]=(row[i][j-1]<0?0:row[i][j-1])+1;
                else if(grid[i][j]=='0')    row[i][j]=row[i][j-1]<0?0:row[i][j-1];
                else    row[i][j]=-1;
            }
            for(int j=grid[0].size()-2; -1<j; j--)  if(row[i][j]!=-1&&row[i][j]<row[i][j+1])    row[i][j]=row[i][j+1];
        }
        
        for(int j=0; j<grid[0].size(); j++){
            if(grid[0][j]=='E') col[0][j]=1;
            for(int i=1; i<grid.size(); i++){
                if(grid[i][j]=='E') col[i][j]=(col[i-1][j]<0?0:col[i-1][j])+1;
                else if(grid[i][j]=='0')    col[i][j]=col[i-1][j]<0?0:col[i-1][j];
                else    col[i][j]=-1;
            }
            for(int i=grid.size()-2; -1<i; i--) if(col[i][j]!=-1&&col[i][j]<col[i+1][j])    col[i][j]=col[i+1][j];
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='0'&&mx<row[i][j]+col[i][j]) mx=row[i][j]+col[i][j];
            }
        }
        
        return mx;
    }
};