

/*
Leetcode 547. Friend Circles

Related Topics 
Depth-first SearchUnion Find
Similar Questions 
Number of Connected Components in an Undirected Graph,
Judge Route Circle, Sentence Similarity, Sentence Similarity II

Next challenges: 
Number of Connected Components in an Undirected Graph, Sentence Similarity II

Test Cases:
[[1,1,0],[1,1,0],[0,0,1]]
[[1,1,0], [1,1,1], [0,1,1]]

Runtime: 22 ms
Your runtime beats 43.62 % of cpp submissions

*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        // union second
        int n=M.size(), i1, j1, cr=M.size();
        vector<pair<int,int>> uf;
        for(int i=0; i<n; i++)  uf.push_back(make_pair(i,1));// ID, #elements
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(M[i][j]!=1)  continue;
                
                for( i1=i; uf[i1].first!=i1; i1=uf[i1].first){
                    uf[i1].first=uf[uf[i1].first].first;// path compression
                }
                
                for( j1=j; uf[j1].first!=j1; j1=uf[j1].first){
                    uf[j1].first=uf[uf[j1].first].first;// path compression
                }
                
                if(i1!=j1){
                    if(uf[i1].second<uf[j1].second){
                        uf[j1].second+=uf[i1].second;
                        uf[j1].first=uf[i1].first;
                    }else{
                        uf[i1].second+=uf[j1].second;
                        uf[i1].first=uf[j1].first;                        
                    }
                    cr--;
                }
            }
        }
        
        return cr;
    }
};


/*
// No pass compression 
// Runtime: 22 ms
// Your runtime beats 43.62 % of cpp submissions.


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        // union second
        int n=M.size(), i1, j1, cr=M.size();
        vector<pair<int,int>> uf;
        for(int i=0; i<n; i++)  uf.push_back(make_pair(i,1));// ID, #elements
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(M[i][j]!=1)  continue;
                
                for( i1=i; uf[i1].first!=i1; i1=uf[i1].first){
                    //uf[i1].first=uf[uf[i1].first].first;// path compression
                }
                
                for( j1=j; uf[j1].first!=j1; j1=uf[j1].first){
                    //uf[j1].first=uf[uf[j1].first].first;// path compression
                }
                
                if(i1!=j1){
                    if(uf[i1].second<uf[j1].second){
                        uf[j1].second+=uf[i1].second;
                        uf[j1].first=uf[i1].first;
                    }else{
                        uf[i1].second+=uf[j1].second;
                        uf[i1].first=uf[j1].first;                        
                    }
                    cr--;
                }
            }
        }
        
        return cr;
    }
};

*/