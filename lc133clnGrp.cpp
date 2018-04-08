
/*
Leetcode 133. Clone Graph

Companies 
Google, Facebook, Uber, Pocket Gems
Related Topics 
Depth-first Search, Breadth-first Search, Graph 
Similar Questions 
Copy List with Random Pointer

Next challenges: Copy List with Random Pointer

Runtime: 28 ms
Your runtime beats 97.21 % of cpp submissions.

*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Nodes are labeled uniquely. DFS/BFS 
        if(!node)   return node;
        unordered_map<int, UndirectedGraphNode *> uc;
            
        return dfs(node, uc);
    }
    
    UndirectedGraphNode * dfs(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>& uc){
        unordered_map<int, UndirectedGraphNode *>::iterator uci=uc.find(node->label);
        if(uci!=uc.end()){
            return uci->second;
        }else{
            UndirectedGraphNode * nd=new UndirectedGraphNode(node->label);
            uc.emplace(node->label, nd);
            for(int i=0; i<node->neighbors.size(); i++){
                nd->neighbors.push_back(dfs(node->neighbors[i], uc));
            }
            return nd;
        }
    }
};
