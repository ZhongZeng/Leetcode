
/*
Leetcode 892. Surface Area of 3D Shapes

Related Topics 
Math, Geometry 

Test Cases:
[[2]]
[[1,2],[3,4]]
[[1,0],[0,2]]
[[1,1,1],[1,0,1],[1,1,1]]
[[2,2,2],[2,1,2],[2,2,2]]

Runtime: 4 ms

*/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        // array, similiar to shadow but different  
        if(grid.size()<1||grid[0].size()<1) return 0;
        int sum=0;
        
        for( int i=0; i<grid.size(); i++){
            for( int j=0; j<grid[i].size(); j++){
                if(grid[i][j]!=0)   sum+=2;
            }
        }
        
        for( int i=0; i<grid.size(); i++){
            sum+=grid[i][0];
            sum+=grid[i].back();
            for( int j=1; j<grid[i].size(); j++){
                if(grid[i][j-1]<grid[i][j]){
                    sum+=grid[i][j]-grid[i][j-1];
                }else if(grid[i][j]<grid[i][j-1]){
                    sum+=grid[i][j-1]-grid[i][j];
                }
            }
        }
        
        for( int j=0; j<grid[0].size(); j++){
            sum+=grid[0][j];
            sum+=grid.back()[j];
            for( int i=1; i<grid.size(); i++){
                if(grid[i-1][j]<grid[i][j]){
                    sum+=grid[i][j]-grid[i-1][j];
                }else if(grid[i][j]<grid[i-1][j]){
                    sum+=grid[i-1][j]-grid[i][j];
                }
            }
        }
        
        return sum;
    }
};
