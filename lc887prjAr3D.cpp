
/*
Leetcode 887. Projection Area of 3D Shapes

Companies  

Related Topics 
Math 

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
    int projectionArea(vector<vector<int>>& grid) {
        int sum=0, mx;
        
        for( int i=0; i<grid.size(); i++){
            for( int j=0; j<grid[0].size(); j++){
                if(grid[i][j]!=0)   sum++;
            }
        }
        
        for( int i=0; i<grid.size(); i++){
            mx=0;
            for( int j=0; j<grid[0].size(); j++){
                if(mx<grid[i][j])   mx=grid[i][j];
            }
            sum+=mx;
        }
        
        for( int j=0; j<grid[0].size(); j++){
            mx=0;
            for( int i=0; i<grid.size(); i++){
                if(mx<grid[i][j])   mx=grid[i][j];
            }
            sum+=mx;
        }
        
        return sum;
    }
};
