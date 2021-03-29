/*
1631. Path With Minimum Effort

Medium

Companies:	Google, Houzz, ByteDance 
Related Topics:	Binary Search, Depth-first Search, Uniond Find, Graph 
Similar Questions:	Path With Maximum Minimum Value

Runtime: 528 ms	Runtime: 528 ms
Memory Usage: 21.9 MB	Your memory usage beats 64.47 % of cpp submissions.
*/

struct cell{
    int x, y, effort;
    cell( int x_, int y_, int effort_){
        x=x_;
        y=y_;
        effort=effort_;
    }
};

struct comp{
    bool operator()(cell c1, cell c2){
        return c1.effort>c2.effort;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Dijkstra's Algorithm 
        vector<vector<int>> visited( heights.size(), vector<int> (heights[0].size(), 0));
        priority_queue<cell, vector<cell>, comp> to_visit;
        addToVisit( 0, 0, 0, 0, 0, heights, visited, to_visit);
        
        while( !to_visit.empty() ){
            cell c=to_visit.top();
            to_visit.pop();
            int x=c.x, y=c.y, this_effort=c.effort;
            if(x==heights.size()-1&&y==heights[0].size()-1) return this_effort;
            
            if(visited[x][y]==1)    continue;
            visited[x][y]=1;
            
            if(0<x) addToVisit( x, y, x-1, y, this_effort, heights, visited, to_visit);
            if(x+1<heights.size())  
                addToVisit( x, y, x+1, y, this_effort, heights, visited, to_visit);
            if(0<y) addToVisit( x, y, x, y-1, this_effort, heights, visited, to_visit);
            if(y+1<heights[0].size())   
                addToVisit( x, y, x, y+1, this_effort, heights, visited, to_visit);
        }
        
        return -1;// won't be triggered
    }
    
protected:
    void addToVisit( int x0, int y0, int x1, int y1, int this_effort, vector<vector<int>>& heights,
            vector<vector<int>>& visited, priority_queue<cell, vector<cell>, comp>& to_visit){
        if(visited[x1][y1]==1)  return ;
        
        int next_effort=abs(heights[x1][y1]-heights[x0][y0]);
        to_visit.push( cell( x1, y1, next_effort<this_effort?this_effort:next_effort));
        
        return ;
    }
};