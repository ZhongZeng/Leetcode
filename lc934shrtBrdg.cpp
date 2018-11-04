
/*
Leetcode 934. Shortest Bridge

Test Cases:
[[0,1],[1,0]]
[[0,1,0],[0,0,0],[0,0,1]]
[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
[[1,1,0,0,0,0],[0,1,0,0,0,0],[1,0,0,0,0,0],[1,1,1,0,0,0],[1,1,0,0,0,0],[0,0,0,0,0,0]]

Runtime: 40 ms

*/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        // BFS from both islands, typical shortest path; O(m*n) time 
        int i, j, bg=0;
        bool b;
        
        for( i=0; i<A.size(); i++){// record 1st island 
            for( j=0, b=false; j<A[i].size(); j++){
                if(A[i][j]==1){
                    dfs1land( i, j, A, 2);
                    b=true;
                    break;
                }
            }
            if(b)   break;
        }
        
        for( ; i<A.size(); i++){// record 2nd island & BFS 
            for( j=0; j<A[i].size(); j++){
                if(A[i][j]==1){
                    bg=dfs2land( i, j, A);
                    return bg;
                }
            }
        }
        
        //for(auto e:A){  for(auto f:e)   cout<<f<<" ";   cout<<endl; }
        
        return bg;
    }
    
protected:    
    int dfs2land( int i, int j, vector<vector<int>>& A){
        int bg, a, b;
        vector<pair<int,int>> vs, va;
        vs.push_back(make_pair(i,j));
        va.push_back(make_pair(i,j));
        A[i][j]=3;
        
        while(!vs.empty()){// DFS, mark 2nd island as 3
            a=vs.back().first;
            b=vs.back().second;
            vs.pop_back();

            if(0<a&&A[a-1][b]==1){
                A[a-1][b]=3;
                vs.push_back(make_pair(a-1,b));
                va.push_back(make_pair(a-1,b));
            }

            if(0<b&&A[a][b-1]==1){
                A[a][b-1]=3;
                vs.push_back(make_pair(a,b-1));
                va.push_back(make_pair(a,b-1));
            }

            if(a+1<A.size()&&A[a+1][b]==1){
                A[a+1][b]=3;
                vs.push_back(make_pair(a+1,b));
                va.push_back(make_pair(a+1,b));
            }

            if(b+1<A[0].size()&&A[a][b+1]==1){
                A[a][b+1]=3;
                vs.push_back(make_pair(a,b+1));
                va.push_back(make_pair(a,b+1));
            }
        }
        
        for( bg=0; !va.empty(); bg++){// BFS 
            vs.clear();
            for( int i=0; i<va.size(); i++){
                a=va[i].first;
                b=va[i].second;
                
                if(0<a){
                    if(A[a-1][b]==0){
                        A[a-1][b]=3;
                        vs.push_back(make_pair(a-1,b));                            
                    }else if(A[a-1][b]==2){
                        return bg;
                    }
                }

                if(0<b){
                    if(A[a][b-1]==0){
                        A[a][b-1]=3;
                        vs.push_back(make_pair(a,b-1));                        
                    }else if(A[a][b-1]==2){
                        return bg;
                    }
                }

                if(a+1<A.size()){
                    if(A[a+1][b]==0){
                        A[a+1][b]=3;
                        vs.push_back(make_pair(a+1,b));                        
                    }else if(A[a+1][b]==2){
                        return bg;
                    }
                }

                if(b+1<A[0].size()){
                    if(A[a][b+1]==0){
                        A[a][b+1]=3;
                        vs.push_back(make_pair(a,b+1));                        
                    }else if(A[a][b+1]==2){
                        return bg;
                    }
                }
            }
            va=vs;
        }
        
        return bg;
    }
    
    void dfs1land(int i, int j, vector<vector<int>>& A, int mk){
        int a, b;
        vector<pair<int,int>> vs;
        vs.push_back(make_pair(i,j));
        A[i][j]=mk;

        while(!vs.empty()){// DFS, mark 1st island as mk 
            a=vs.back().first;
            b=vs.back().second;
            vs.pop_back();

            if(0<a&&A[a-1][b]==1){
                A[a-1][b]=mk;
                vs.push_back(make_pair(a-1,b));
            }

            if(0<b&&A[a][b-1]==1){
                A[a][b-1]=mk;
                vs.push_back(make_pair(a,b-1));
            }

            if(a+1<A.size()&&A[a+1][b]==1){
                A[a+1][b]=mk;
                vs.push_back(make_pair(a+1,b));
            }

            if(b+1<A[0].size()&&A[a][b+1]==1){
                A[a][b+1]=mk;
                vs.push_back(make_pair(a,b+1));
            }
        }
        
        return ;
    }
};
