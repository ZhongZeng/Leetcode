/*
994. Rotting Oranges

Related Topics: Breadth-first Search 

Test Cases:
[[2,1,1],[1,1,0],[0,1,1]]
[[2,1,1],[0,1,1],[1,0,1]]
[[0,2]]
[[1,2]]

Runtime: 12 ms
Memory Usage: 11 MB
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {// BFS
        int fh=0, mt=0;
        vector<pair<int,int>> vr, ur;
        
        for( int i=0; i<grid.size(); i++){// record initial rotted & #fresh 
            for( int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1)   fh++;
                else if(grid[i][j]==2)  vr.push_back(make_pair(i,j));
            }
        }
        
        for( ; 0<fh&&0<vr.size(); mt++){// BFS 
            ur.clear();
            for( int i=0; i<vr.size(); i++){
                int x=vr[i].first, y=vr[i].second;
                if(0<x&&grid[x-1][y]==1)    rot(grid,ur,fh,x-1,y);
                if(0<y&&grid[x][y-1]==1)    rot(grid,ur,fh,x,y-1);
                if(x<grid.size()-1&&grid[x+1][y]==1)    rot(grid,ur,fh,x+1,y);
                if(y<grid[0].size()-1&&grid[x][y+1]==1) rot(grid,ur,fh,x,y+1);
            }
            vr=ur;
        }
        
        return fh==0?mt:-1;
    }

protected:
    void rot(vector<vector<int>>& grid, vector<pair<int,int>>& ur, int& fh, int x, int y){
        fh--;
        grid[x][y]=-1;// update & avoid duplication for fh&ur
        ur.push_back(make_pair(x,y));
        return ;
    }
};