/*
1034. Coloring A Border

Companies	Booking
Related Topics	Depth-first Search
Similar Questions	Island Perimeter

Test Cases:
[[1,1],[1,2]]
0
0
3
[[1,1,1],[1,1,1],[1,1,1]]
1
1
2

Next challenges: Matchsticks to Square, Number of Distinct Islands II, Flip Binary Tree To Match Preorder Traversal

Runtime: 52 ms	Your runtime beats 94.16 % of cpp submissions.
Memory Usage: 12.2 MB	Your memory usage beats 89.31 % of cpp submissions.
*/

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        // dfs, O(2*n) time&space, color in [1,1000]; square => connected component => border: edges in component
        if(grid[r0][c0]==color) return grid;// color!=component color 
        dfsFlip( grid, r0, c0, color);// flip&color 
        dfsRev( grid, r0, c0);// reverse colors for components&edges
        return grid;
    }
    
protected:
    void dfsFlip( vector<vector<int>>& grid, int r0, int c0, int& color){// in grid&&component guranteed
        int comp=grid[r0][c0];// 0<comp
        grid[r0][c0]=-grid[r0][c0];// 0<grid[r0][c0] guranteed; mark as visited
        
        if(0<r0){// up 
            if(grid[r0-1][c0]==comp)    dfsFlip( grid, r0-1, c0, color);
            else if(grid[r0-1][c0]<0)  ;// visited 
            else    grid[r0][c0]=-color;// border 
        }else{
            grid[r0][c0]=-color;// border 
        }

        if(r0+1<grid.size()){// down 
            if(grid[r0+1][c0]==comp)    dfsFlip( grid, r0+1, c0, color);
            else if(grid[r0+1][c0]<0)  ;// visited 
            else    grid[r0][c0]=-color;// border 
        }else{
            grid[r0][c0]=-color;// border 
        }

        if(0<c0){// left 
            if(grid[r0][c0-1]==comp)    dfsFlip( grid, r0, c0-1, color);
            else if(grid[r0][c0-1]<0)  ;// visited 
            else    grid[r0][c0]=-color;// border
        }else{
            grid[r0][c0]=-color;// border 
        }

        if(c0+1<grid[0].size()){// right 
            if(grid[r0][c0+1]==comp)    dfsFlip( grid, r0, c0+1, color);
            else if(grid[r0][c0+1]<0)  ;// visited 
            else    grid[r0][c0]=-color;// border
        }else{
            grid[r0][c0]=-color;// border 
        }
        
        return ;
    }
    
    void dfsRev( vector<vector<int>>& grid, int r0, int c0){
        if(0<grid[r0][c0])  return ;
        grid[r0][c0]=-grid[r0][c0];
        
        if(0<r0)    dfsRev( grid, r0-1, c0);// up 
        if(r0+1<grid.size())    dfsRev( grid, r0+1, c0);// down 
        if(0<c0)    dfsRev( grid, r0, c0-1);// left 
        if(c0+1<grid[0].size()) dfsRev( grid, r0, c0+1);// right 
        
        return ;
    }
};