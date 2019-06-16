/*
1091. Shortest Path in Binary Matrix

Test Cases:
[[0,1],[1,0]]
[[0,0,0],[1,1,0],[1,1,0]]
[[1,0,0],[1,1,0],[1,1,0]]

Runtime: 52 ms
Memory Usage: 13 MB
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // BFS, Dijkstra
        if(grid[0][0]==1)   return -1;// corner case
        int rt=0;
        vector<pair<int,int>> hp={make_pair(0,0)}, hq;// 1 distance b/t 2 adjacent cells, thus pair is enough
        grid[0][0]=-1;// -1: visited||to visit in next step
        
        for( ; 0<hp.size(); rt++){
            hq.clear();
            for( int i=0; i<hp.size(); i++){
                if(hp[i].first==grid.size()-1&&hp[i].second==grid[0].size()-1)  return rt+1;// suitable for rt==1
                push_cell(grid, hq, hp[i].first-1, hp[i].second-1);
                push_cell(grid, hq, hp[i].first-1, hp[i].second);
                push_cell(grid, hq, hp[i].first-1, hp[i].second+1);
                push_cell(grid, hq, hp[i].first, hp[i].second-1);
                push_cell(grid, hq, hp[i].first, hp[i].second+1);
                push_cell(grid, hq, hp[i].first+1, hp[i].second-1);
                push_cell(grid, hq, hp[i].first+1, hp[i].second);
                push_cell(grid, hq, hp[i].first+1, hp[i].second+1);
            }
            hp=hq;
        }
        
        return -1;
    }
    
protected:
    void push_cell(vector<vector<int>>& grid, vector<pair<int,int>>& hq, int x, int y){
        if(-1<x&&-1<y&&x<grid.size()&&y<grid[0].size()&&grid[x][y]==0){
            grid[x][y]=-1;
            hq.push_back(make_pair(x,y));
        }
        return ;
    }
};