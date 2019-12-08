/*
1129. Shortest Path with Alternating Colors

Tag:	Breadth-first Search 

Test Case:
3
[[0,1]]
[[2,1]]

Runtime: 28 ms
Memory Usage: 14.8 MB
*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        // BFS; directed graph; n in [1,100] 
        unordered_map<int,unordered_set<int>> re=recordEdge( red_edges), be=recordEdge( blue_edges);
        vector<int> rp(n,-1), bp(n,-1);// shortest path ending at pr/pb[i] with red/blue edge
        rp[0]=0;
        bp[0]=0;
        vector<int> rv={0}, bv={0};// red/blue edges leading to next node 
        
        for( int st=0; 0<rv.size()||0<bv.size(); st++){// st: steps
            vector<int> bu=bfs_( rv, be, bp, st), ru=bfs_( bv, re, rp,st);
            rv=ru;
            bv=bu;
        }
        
        for( int i=0; i<rp.size(); i++){
            if(rp[i]==-1||(bp[i]!=-1&&bp[i]<rp[i])) rp[i]=bp[i];
        }
        
        return rp;
    }
    
protected:
    unordered_map<int,unordered_set<int>> recordEdge( vector<vector<int>>& red_edges){
        unordered_map<int,unordered_set<int>> re;
        for( int i=0; i<red_edges.size(); i++){
            unordered_map<int,unordered_set<int>>::iterator umi=re.find(red_edges[i][0]);
            if(umi!=re.end()){
                umi->second.emplace(red_edges[i][1]);
            }else{
                unordered_set<int> us={red_edges[i][1]};
                re.emplace( red_edges[i][0], us);
            }
        }
        return re;
    }
    
    vector<int> bfs_( vector<int>& vr, unordered_map<int,unordered_set<int>>& be, vector<int>& bp, int st){
        vector<int> ub;
        for( int i=0; i<vr.size(); i++){
            unordered_map<int,unordered_set<int>>::iterator bei=be.find(vr[i]);
            if(bei==be.end())   continue;
            for( unordered_set<int>::iterator usj=bei->second.begin(); usj!=bei->second.end(); usj++){
                if(bp[*usj]==-1){
                    bp[*usj]=st+1;
                    ub.push_back(*usj);
                }
            }
        }
        return ub;
    }
    
};