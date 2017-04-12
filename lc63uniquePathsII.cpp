

/*
Leetcode 63. Unique Paths II
You are here! 
Your runtime beats 24.82% of cpp submissions. 3 ms
*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // O(1) space, O(m*n) time
        int row=obstacleGrid.size();
        int col=0;
        if(row) col=obstacleGrid[0].size();
        
        if(obstacleGrid[row-1][col-1]!=1){
            obstacleGrid[row-1][col-1]=1;
        }else{    
            return 0;
        }
        
        for(int i=row-1; i!=0; i--){
            if(obstacleGrid[i-1][col-1]!=1){
                obstacleGrid[i-1][col-1]=obstacleGrid[i-1][col-1]+obstacleGrid[i][col-1];
            }else{
                obstacleGrid[i-1][col-1]=0;
            }
            // cout<<obstacleGrid[i-1][col-1]<<endl;
        }
        
        for(int i=col-1; i!=0; i--){
            if(obstacleGrid[row-1][i-1]!=1){
                obstacleGrid[row-1][i-1]=obstacleGrid[row-1][i-1]+obstacleGrid[row-1][i];
            }else{
                obstacleGrid[row-1][i-1]=0;
            }
            // cout<<obstacleGrid[row-1][i-1]<<endl;
        }
        
        for(int i=row-1; i!=0; i--){
            for(int j=col-1; j!=0; j--){
                if(obstacleGrid[i-1][j-1]!=1){
                    obstacleGrid[i-1][j-1]+=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                }else{
                    obstacleGrid[i-1][j-1]=0;
                }
                // cout<<obstacleGrid[i-1][j-1]<<endl;
            }
        }
        
        return obstacleGrid[0][0];
    }
};

