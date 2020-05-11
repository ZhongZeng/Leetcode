/*
1443. Minimum Time to Collect All Apples in a Tree

Companies	Facebook
Related Topics	Tree, Depth-first Search

Test Cases:
7
[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
[false,false,true,false,true,true,false]
7
[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
[false,false,true,false,false,true,false]
7
[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
[false,false,false,false,false,false,false]

Runtime: 716 ms
Memory Usage: 68.8 MB
*/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // post-order DFS, Tree, Hash Table; O(n) Time&Space
        vector<int> visited(n,0);
        unordered_map<int,vector<int>> edgs;
        for( int i=0; i<edges.size(); i++){
            addEdge( edges[i][0], edges[i][1], edgs);
            addEdge( edges[i][1], edges[i][0], edgs);
        }
        pair<bool,int> pr=dfs( 0, edgs, hasApple, visited);// no need to count path just need # of vertices
        return pr.first?pr.second:0;
    }
    
protected:
    void addEdge( int v, int u, unordered_map<int,vector<int>> & edgs){
        unordered_map<int,vector<int>>::iterator it=edgs.find(v);
        if(it!=edgs.end())  it->second.push_back(u);
        else    edgs.emplace(v, vector<int> {u});
        return;
    }
    
    pair<bool,int> dfs( int v, unordered_map<int,vector<int>> & edgs, vector<bool> & hasApple, 
            vector<int> & visited){// visited can be replaced with the previous vertice 
        int sum=0;
        bool has=false;
        unordered_map<int,vector<int>>::iterator it=edgs.find(v);
        visited[v]=1;
        
        for( int i=0; i<it->second.size(); i++){
            if(visited[it->second[i]]==0){
                pair<bool,int> pr=dfs( it->second[i], edgs, hasApple, visited);
                if(pr.first==true){
                    has=true;
                    sum+=pr.second+2;
                }
            }
        }
        
        if(has==false){
            if(hasApple[v]==true)   return make_pair(true, 0);
            else    return make_pair(false, 0);
        }else{
            return make_pair(true, sum);
        }
    }
};