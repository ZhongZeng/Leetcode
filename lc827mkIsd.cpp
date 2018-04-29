
/*

Leetcode 827. Making A Large Island

Test Cases:
[[1,0],[0,1]]
[[1, 1], [1, 0]]
[[1, 1], [1, 1]]
[[0,0,0,0,0,0,0],[0,1,1,1,1,0,0],[0,1,0,0,1,0,0],[1,0,1,0,1,0,0],[0,1,0,0,1,0,0],[0,1,0,0,1,0,0],[0,1,1,1,1,0,0]]

22 ms

*/

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        // DFS, O(m*n) time, O(# of 1s) space
        // 1 <= grid.length = grid[0].length <= 50.
        // 0 <= grid[i][j] <= 1 
        int id=2, mx=1, mt;
        unordered_map<int, int> ar;
        ar.emplace(0, 1);
        unordered_set<int> us;
        unordered_set<int>::iterator usi;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1)   ar.emplace( id++, dfs( i, j, grid, id) );
            }
        }
        
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                us.clear();
                us.emplace(grid[r][c]);
                mt=ar.find(grid[r][c])->second;
                
                if(0<r&&us.find(grid[r-1][c])==us.end()){
                    us.emplace(grid[r-1][c]);
                    mt+=ar.find(grid[r-1][c])->second;
                }
                if(0<c&&us.find(grid[r][c-1])==us.end()){
                    us.emplace(grid[r][c-1]);
                    mt+=ar.find(grid[r][c-1])->second;                       
                }
                if(r+1<grid.size()&&us.find(grid[r+1][c])==us.end()){
                    us.emplace(grid[r+1][c]);
                    mt+=ar.find(grid[r+1][c])->second;
                }
                if(c+1<grid[0].size()&&us.find(grid[r][c+1])==us.end()){
                    us.emplace(grid[r][c+1]);
                    mt+=ar.find(grid[r][c+1])->second;
                }
                
                if(mx<mt)   mx=mt;
                //cout<<mt<<" ";
                //cout<<grid[r][c]<<" ";
            }
            //cout<<endl;
        }
                
        return mx;
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid, int& id){
        int area=0, r, c;
        vector<pair<int,int>> vp;
        grid[i][j]=id;
        vp.push_back(make_pair(i,j));
        
        while(!vp.empty()){
            r=vp.back().first;
            c=vp.back().second;
            vp.pop_back();
            area++;
            if(0<r&&grid[r-1][c]==1){
                grid[r-1][c]=id;
                vp.push_back(make_pair(r-1, c));
            }    
            if(0<c&&grid[r][c-1]==1){
                grid[r][c-1]=id;
                vp.push_back(make_pair(r, c-1));
            }    
            if(r+1<grid.size()&&grid[r+1][c]==1){
                grid[r+1][c]=id;
                vp.push_back(make_pair(r+1, c));
            }    
            if(c+1<grid[0].size()&&grid[r][c+1]==1){
                grid[r][c+1]=id;
                vp.push_back(make_pair(r, c+1));
            }
        }
        
        return area;
    }
};