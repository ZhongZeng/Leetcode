

/*
Leetcode 684. Redundant Connection

Related Topics 
Tree, Union Find, Graph
Similar Questions 
Redundant Connection II, Accounts Merge

Runtime: 6 ms
Your runtime beats 37.01 % of cpp submissions.

Test Cases:
[[1,2],[1,3],[2,3]]
[[1,2], [2,3], [3,4], [1,4], [1,5]]

*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // This is my very FIRST Union Find program. 
        // Union Find; weighted quick union+path compression, learned from Algo-Princeton. 
        // If 2 nodes are already connected, that edge is redudant. 
        // The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), 
        // with one additional edge added.
        int mx=-1, a, b;
        vector<pair<int,int>> vc;
        
        for(int i=0; i<edges.size(); i++){
            if(mx<edges[i][0])  mx=edges[i][0];
            if(mx<edges[i][1])  mx=edges[i][1];
        }
        
        for(int i=0; i<mx+1; i++)
            vc.push_back(make_pair(i,1));
        
        for(int i=0; i<edges.size(); i++){
            a=edges[i][0];
            b=edges[i][1];

            while(vc[a].first!=a){
                vc[a].first=vc[vc[a].first].first;// path compression
                a=vc[a].first;
            }   
            while(vc[b].first!=b){
                vc[b].first=vc[vc[b].first].first;// path compression
                b=vc[b].first;
            }   
            //cout<<a<<" "<<b<<endl;
            
            if(a==b){
                cout<<endl;
                return edges[i];
            }else{
                if(vc[a].second<vc[b].second){
                    vc[b].second+=vc[a].second;
                    vc[b].first=vc[a].first;
                }else{
                    vc[a].second+=vc[b].second;
                    vc[a].first=vc[b].first;
                }                
            }
        }
        
        return {-1,-1};
    }
    
};

/*
// no pass compression
// Runtime: 9 ms
// Your runtime beats 23.53 % of cpp submissions.

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // This is my very FIRST Union Find program. 
        // Union Find; weighted quick union+path compression, learned from Algo-Princeton. 
        // If 2 nodes are already connected, that edge is redudant. 
        // The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), 
        // with one additional edge added.
        int mx=-1, a, b;
        vector<pair<int,int>> vc;
        
        for(int i=0; i<edges.size(); i++){
            if(mx<edges[i][0])  mx=edges[i][0];
            if(mx<edges[i][1])  mx=edges[i][1];
        }
        
        for(int i=0; i<mx+1; i++)
            vc.push_back(make_pair(i,1));
        
        for(int i=0; i<edges.size(); i++){
            a=edges[i][0];
            b=edges[i][1];

            while(vc[a].first!=a){
                //vc[a].first=vc[vc[a].first].first;// path compression
                a=vc[a].first;
            }   
            while(vc[b].first!=b){
                //vc[b].first=vc[vc[b].first].first;// path compression
                b=vc[b].first;
            }   
            //cout<<a<<" "<<b<<endl;
            
            if(a==b){
                cout<<endl;
                return edges[i];
            }else{
                if(vc[a].second<vc[b].second){
                    vc[b].second+=vc[a].second;
                    vc[b].first=vc[a].first;
                }else{
                    vc[a].second+=vc[b].second;
                    vc[a].first=vc[b].first;
                }                
            }
        }
        
        return {-1,-1};
    }
    
};

*/
