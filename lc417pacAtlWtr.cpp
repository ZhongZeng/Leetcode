

/*
Leetcode 417. Pacific Atlantic Water Flow

Next challenges: Trapping Rain Water II,
The Maze II, Cheapest Flights Within K Stops

Companies 
Google 
Related Topics 
Depth-first Search, Breadth-first Search 

Test Cases:
[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
[]

Runtime: 46 ms
Your runtime beats 59.33 % of cpp submissions.

*/


class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // DFS; O(m*n) time&space 
        int i, j;
        // 0:unvisited; -1:pacific; -2:atlantic; -3:both
        vector<pair<int, int>> rt, vc, vd;
        if(matrix.size()<1||matrix[0].size()<1) return rt;
        vector<int> v(matrix[0].size(), 0);
        vector<vector<int>> vv(matrix.size(), v);
        
        // pacific 
        for( j=0; j<matrix[0].size(); j++)  pacPt(0, j, vc, vv);
        for( i=0; i<matrix.size(); i++) pacPt(i, 0, vc, vv);
        pac(vc, vv, matrix);
        
        // atlantic 
        vc.clear();
        for( j=0; j<matrix[0].size(); j++)  atlPt(matrix.size()-1, j, vc, vv);
        for( i=0; i<matrix.size(); i++) atlPt(i, matrix[0].size()-1, vc, vv);
        atl(vc, vv, matrix);
        
        // both 
        for( i=0; i<matrix.size(); i++){
            for( j=0; j<matrix[0].size(); j++){
                if(vv[i][j]==-3)    rt.push_back(make_pair(i,j));
            }
        }
        
        return rt;
    }
    
protected:    
    void pac(vector<pair<int,int>>& vc, vector<vector<int>>& vv, vector<vector<int>>& matrix){
        int i, j;
        while(!vc.empty()){
            i=vc.back().first;
            j=vc.back().second;
            vc.pop_back();
            if(0<i&&matrix[i][j]<=matrix[i-1][j])   pacPt(i-1, j, vc, vv);
            if(0<j&&matrix[i][j]<=matrix[i][j-1])   pacPt(i, j-1, vc, vv);
            if(i<matrix.size()-1&&matrix[i][j]<=matrix[i+1][j]) pacPt(i+1, j, vc, vv);
            if(j<matrix[0].size()-1&&matrix[i][j]<=matrix[i][j+1])  pacPt(i, j+1, vc, vv);
        }
        return ;
    }
    
    void pacPt(int i, int j, vector<pair<int, int>>& vd, vector<vector<int>>& vv){
        if(vv[i][j]!=-1){
            vv[i][j]=-1;
            vd.push_back(make_pair(i,j));
        }
        return ;
    }
    
    void atl(vector<pair<int,int>>& vc, vector<vector<int>>& vv, vector<vector<int>>& matrix){
        int i, j;
        while(!vc.empty()){
            i=vc.back().first;
            j=vc.back().second;
            vc.pop_back();
            if(0<i&&matrix[i][j]<=matrix[i-1][j])   atlPt(i-1, j, vc, vv);
            if(0<j&&matrix[i][j]<=matrix[i][j-1])   atlPt(i, j-1, vc, vv);
            if(i<matrix.size()-1&&matrix[i][j]<=matrix[i+1][j]) atlPt(i+1, j, vc, vv);
            if(j<matrix[0].size()-1&&matrix[i][j]<=matrix[i][j+1])   atlPt(i, j+1, vc, vv);            
        }
        return ;
    }
    
    void atlPt(int i, int j, vector<pair<int, int>>& vc, vector<vector<int>>& vv){
        if(vv[i][j]==-1){
            vv[i][j]=-3;
            vc.push_back(make_pair(i,j));
        }else if(vv[i][j]==0){
            vv[i][j]=-2;
            vc.push_back(make_pair(i,j));
        }
        return ;
    }
};
