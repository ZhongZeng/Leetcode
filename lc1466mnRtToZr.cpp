/*
1466. Reorder Routes to Make All Paths Lead to the City Zero

Related Topics	Tree, Depth-first Search

Test Cases:
6
[[0,1],[1,3],[2,3],[4,0],[4,5]]
5
[[1,0],[1,2],[3,2],[3,4]]
3
[[1,0],[2,0]]

Runtime: 1056 ms
Memory Usage: 44.4 MB
*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // DFS or BFS; O(n) time; this is a tree(fully-connected directed acyclical graph) with n nodes and (n-1) edges
        unordered_map<int,vector<pair<int,int>>> edges;// node, connected node and direction
        vector<int> visited(n,0);
        visited[0]=1;
        
        for( int i=0; i<connections.size(); i++){
            addEdge( connections[i][0], connections[i][1], 0, edges);// d==0: from b to e
            addEdge( connections[i][1], connections[i][0], 1, edges);// d==1: from e to b
        }
        
        return dfs( 0, visited, edges);
    }
    
protected:
    void addEdge( int b, int e, int d, unordered_map<int,vector<pair<int,int>>> & edges){
        unordered_map<int,vector<pair<int,int>>>::iterator it=edges.find(b);
        if(it!=edges.end()) it->second.push_back(make_pair(e,d));
        else    edges.emplace( b, vector<pair<int,int>> {make_pair(e,d)});
        return ;
    }
    
    int dfs( int b, vector<int> & visited, unordered_map<int,vector<pair<int,int>>> & edges){
        int sum=0;
        unordered_map<int,vector<pair<int,int>>>::iterator it=edges.find(b);
        for( int i=0; i<it->second.size(); i++){
            int e=it->second[i].first, d=it->second[i].second;
            if(visited[e]==0){
                visited[e]=1;
                sum+=dfs( e, visited, edges)+(d==0?1:0);
            }
        }
        return sum;
    }
};