/*
1519. Number of Nodes in the Sub-Tree With the Same Label

Medium
Companies	Samsung
Related Topics	Depth-first Search, Breadt-first Search

Test Cases:
7
[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
"abaedcd"
4
[[0,1],[1,2],[0,3]]
"bbbb"
5
[[0,1],[0,2],[1,3],[0,4]]
"aabab"
6
[[0,1],[0,2],[1,3],[3,4],[4,5]]
"cbabaa"
7
[[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]]
"aaabaaa"

Runtime: 1284 ms	Your runtime beats 52.00 % of cpp submissions.
Memory Usage: 275 MB	Your memory usage beats 6.24 % of cpp submissions.
*/

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // DFS; O(26*n) time
        unordered_map<int,unordered_set<int>> edge_map;
        vector<int> counts(n,-1);
        for( int i=0; i<edges.size(); i++){
            addEdge( edges[i][0], edges[i][1], edge_map);
            addEdge( edges[i][1], edges[i][0], edge_map);
        }
        dfs( -1, 0, counts, labels, edge_map);
        return counts;
    }
    
protected:
    void addEdge( int b, int e, unordered_map<int,unordered_set<int>> & edge_map){
        unordered_map<int,unordered_set<int>>::iterator it=edge_map.find(b);
        if(it!=edge_map.end())  it->second.emplace(e);
        else    edge_map[b]=unordered_set<int> {e};
        return ;
    }
    
    vector<int> dfs( int parent, int node, vector<int> & counts, 
                    string & labels, unordered_map<int,unordered_set<int>> & edge_map){
        vector<int> letters(26, 0);
        unordered_map<int,unordered_set<int>>::iterator it=edge_map.find(node);
        
        for( unordered_set<int>::iterator jt=it->second.begin(); jt!=it->second.end(); jt++){
            if(*jt==parent) continue;
            vector<int> vc=dfs( node, *jt, counts, labels, edge_map);
            for( int i=0; i<letters.size(); i++)    letters[i]+=vc[i];
        }
        letters[labels[node]-'a']+=1;// count current node
        counts[node]=letters[labels[node]-'a'];
        return letters;
    }
};