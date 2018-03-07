
/*
Leetcode 490. The Maze

Companies 
Google 
Related Topics 
Breadth-first Search, Depth-first Search 
Similar Questions 
The Maze III, The Maze II

Next challenges: The Maze III, The Maze II

Test Cases:
[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[4,4]
[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[3,2]

Runtime: 28 ms
Your runtime beats 80.15 % of cpp submissions.

*/

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // DFS, O(m*n), each element visited at most twice; -1:reachable 
        int i, j, x, y;
        vector<pair<int,int>> vc;
        vc.push_back(make_pair(start[0],start[1]));
        
        while(!vc.empty()){
            i=vc.back().first;
            j=vc.back().second;
            maze[i][j]=-1;
            vc.pop_back();
            //cout<<i<<","<<j<<" ";
            
            for( x=i; 0<x&&maze[x-1][j]!=1; x--){}
            if(reachable(maze, x, j, vc, destination))    return true;

            for( x=i; x<maze.size()-1&&maze[x+1][j]!=1; x++){}
            if(reachable(maze, x, j, vc, destination))    return true;
            
            for( y=j; 0<y&&maze[i][y-1]!=1; y--){}
            if(reachable(maze, i, y, vc, destination))    return true;

            for( y=j; y<maze[0].size()-1&&maze[i][y+1]!=1; y++){}
            if(reachable(maze, i, y, vc, destination))    return true;
        }
        
        return false;
    }
    
    bool reachable(vector<vector<int>>& maze, int x, int y, vector<pair<int,int>>& vc, vector<int>& destination){
        if(maze[x][y]==0){
            if(x==destination[0]&&y==destination[1])    return true;
            maze[x][y]=-1;
            vc.push_back(make_pair(x,y));
        }
        return false;
    }
};