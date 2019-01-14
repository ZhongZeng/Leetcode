/*
310. Minimum Height Trees

Companies   
Google 
Related Topics 
Breadth-first Search, Graph 
Similar Questions 
Course Schedule, Course Schedule II

Test Cases: 
6
[[0,1],[0,2],[0,3],[3,4],[4,5]]
1
[]
4
[[1,0],[1,2],[1,3]]
6
[[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

Next challenges: Reconstruct Itinerary, K-Similar Strings, Snakes and Ladders

Runtime: 56 ms
Your runtime beats 57.06 % of cpp submissions.

Learned Topological sort via BFS in this problem! 
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // second longest&longest path from the node to a leaf
        int m=n, t;// # nodes unremoved 
        vector<int> rt, rm(n,1), vt, ut;// rm:1-unremoved,0-removed; vt,ut: leaf nodes in BFS topological sort 
        unordered_map<int,vector<int>> nb;// neighbors
        unordered_map<int,vector<int>>::iterator nbi;
        unordered_map<int,int> nn;// # neighbors 
        unordered_map<int,int>::iterator nni;
        if(m<3) return getRoot(rm);// corner case 
        
        for( int i=0; i<edges.size(); i++){// construct graph 
            addEdge( edges[i].first, edges[i].second, nb, nn);
            addEdge( edges[i].second, edges[i].first, nb, nn);
        }
        
        for( nni=nn.begin(); nni!=nn.end(); nni++){// find initial leaf 
            if(nni->second==1)  vt.push_back(nni->first);
        }
        
        while(!vt.empty()){// BFS topological sort 
            for( int i=0; i<vt.size(); i++) rm[vt[i]]=0;// remove leaves 
            m-=vt.size();
            if(m<3) return getRoot(rm);// m==1||m==2; m!=0 guranteed to be proved 
            
            ut.clear();
            for( int i=0; i<vt.size(); i++){// update the degree of i's neighbors 
                nbi=nb.find(vt[i]);
                for( int j=0; j<nbi->second.size(); j++){
                    t=nbi->second[j];// t is i's neighbor 
                    if(rm[t]==1){// unremoved 
                        nni=nn.find(t);// guranteed to be found 
                        nni->second-=1;
                        if(nni->second==1)  ut.push_back(t);// push leaves to ut 
                    }
                }
            }
            vt=ut;
        }
        
        return rt;
    }
    
protected:
    vector<int> getRoot(vector<int>& rm){
        vector<int> rt;
        for( int i=0; i<rm.size(); i++) if(rm[i]==1)    rt.push_back(i);
        return rt;
    }
    
    void addEdge( int i, int j, unordered_map<int,vector<int>>& nb, unordered_map<int,int>& nn){
        unordered_map<int,vector<int>>::iterator nbi=nb.find(i);
        if(nbi!=nb.end())   nbi->second.push_back(j);
        else    nb.emplace( i, vector<int>(1,j));
        
        unordered_map<int,int>::iterator nni=nn.find(i);
        if(nni!=nn.end())   nni->second+=1;
        else    nn.emplace(i,1);
        return ;
    }
};
