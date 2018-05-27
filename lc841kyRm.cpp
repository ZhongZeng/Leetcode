
/*
Leetcode 841. Keys and Rooms

Companies 
Google
Related Topics 
Depth-first Search, Graph 

Test Cases:
[[1],[2],[3],[]]
[[1,3],[3,0,1],[2],[0]]

Runtime: 9 ms

*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // DFS, hash table
        // 1 <= rooms.length <= 1000
        // 0 <= rooms[i].length <= 1000
        vector<int> vr(rooms.size(), 0);// visited(0-unvisited, 1-visited)
        
        dfs(rooms, vr, 0);
        //for(auto e:vr)  cout<<e<<" ";   cout<<endl;
        
        for(int i=0; i<vr.size(); i++)  if(vr[i]<1) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<int>& vr, int i){
        if(0<vr[i]) return;
        vr[i]=1;
        
        for(int j=0; j<rooms[i].size(); j++)    dfs(rooms, vr, rooms[i][j]);
        
        return ;
    }
};