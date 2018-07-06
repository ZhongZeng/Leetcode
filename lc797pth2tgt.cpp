
/*
Leetcode 797. All Paths From Source to Target

Test Case:
[[1,2],[3],[3],[]]

Next challenges: Read N Characters Given Read4 II - Call multiple times, 
Range Sum Query - Mutable, Find And Replace in String

Runtime: 56 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> rt;
        vector<int> vc={0};
        
        dfs( vc, rt, graph);
        
        return rt;
    }
    
    void dfs( vector<int>& vc, vector<vector<int>>& rt, vector<vector<int>>& graph){
        if(vc.back()==graph.size()-1){
            rt.push_back(vc);
            return ;
        }
        
        for( int j=0; j<graph[vc.back()].size(); j++){
            vc.push_back(graph[vc.back()][j]);
            dfs( vc, rt, graph);
            vc.pop_back();
        }
        
        return ;
    }
};
