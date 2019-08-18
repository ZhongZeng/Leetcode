/*
1162. As Far from Land as Possible

Companies	Uipath
Related Topics	Breadth-first Search, Graph 
Similar Questions	Shortest Distance from All Buildings

Test Cases:
[[1,1,1,1,1],[1,1,1,1,1],[1,1,1,1,1],[1,1,1,1,1],[1,1,1,1,1]]
[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
[[1,0,1],[0,0,0],[1,0,1]]
[[1,0,0],[0,0,0],[0,0,0]]

Runtime: 48 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 19 MB
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // BFS, O(n) time; classic longest distance problem 
        int d=-1;// no land
        vector<int> land;
        for( int i=0; i<grid.size(); i++){
            for( int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    land.push_back(i);
                    land.push_back(j);
                }
            }
        }
        
        while( !land.empty() ){
            d++;
            vector<int> water;
            for( int i=0; i<land.size(); i+=2){
                BFSLand( land[i]-1, land[i+1], water, grid);
                BFSLand( land[i]+1, land[i+1], water, grid);
                BFSLand( land[i], land[i+1]+1, water, grid);
                BFSLand( land[i], land[i+1]-1, water, grid);
            }
            land=water;
        }
        
        return d<1?-1:d;
    }
    
protected:
    void BFSLand( int r, int c, vector<int>& water, vector<vector<int>>& grid){
        if(-1<r&&r<grid.size()&&-1<c&&c<grid[0].size()&&grid[r][c]==0){
            water.push_back(r);
            water.push_back(c);
            grid[r][c]=1;
        }
        return ;
    }
};