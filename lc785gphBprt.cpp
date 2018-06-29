

/*
Leetcode 785. Is Graph Bipartite?

Companies 
Facebook
Related Topics 
Depth-first Search, Breadth-first Search, Graph 

Test Cases: 
[[1,3],[0,2],[1,3],[0,2]]
[[1,2,3], [0,2], [0,1,3], [0,2]]
[[1],[0],[3],[2]]
[[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]

Next challenges: Trapping Rain Water II, The Maze II, Lonely Pixel II

Runtime: 35 ms
Your runtime beats 17.80 % of cpp submissions.

*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // BFS, nodes of each edge belong to 2 diff sets. No self edges or parallel edges. May not be connected. 
        int t;
        vector<int> vt(graph.size(), -1), vb, vc;
        
        for( int k=0, id=0; k<graph.size(); k++, id+=2 ){
            if(vt[k]==-1){
                vt[k]=id;
                vb.clear();
                vb.push_back(k);
                
                while(!vb.empty()){
                    vc.clear();
                    for( int i=0; i<vb.size(); i++){
                        for( int j=0; j<graph[vb[i]].size(); j++){
                            t=graph[vb[i]][j];
                            if(vt[t]==-1){
                                vt[t]=id+1;
                                vc.push_back(t);
                            }else if(vt[t]==id){
                                return false;
                            }
                        }
                    }

                    vb.clear();
                    for( int i=0; i<vc.size(); i++){
                        for( int j=0; j<graph[vc[i]].size(); j++){
                            t=graph[vc[i]][j];
                            if(vt[t]==-1){
                                vt[t]=id;
                                vb.push_back(t);
                            }else if(vt[t]==id+1){
                                return false;
                            }
                        }
                    }         
                }                
            }
        }
        
        return true;
    }
};
