/*
1020. Number of Enclaves
Similiar to Number of Islands 

Companies   
Google
Related Topics 
Depth-first Search 

Test Cases:
[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
[[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]

Runtime: 56 ms
Memory Usage: 14.7 MB

*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        // DFS, O(m*n) time
        int rt=0;
        
        // DFS from boundaries
        for( int i=0; i<A.size(); i++){
            dfs( A, i, 0);
            dfs( A, i, A[i].size()-1);
        }
        for( int j=0; j<A[0].size(); j++){
            dfs( A, 0, j);
            dfs( A, A.size()-1, j);
        }
        
        for( int i=0; i<A.size(); i++){
            for( int j=0; j<A[i].size(); j++){
                if(A[i][j]==1)  rt+=1;
            }
        }
        
        return rt;
    }

protected:
    void dfs(vector<vector<int>>& A, int i, int j){
        if(A[i][j]!=1)  return ;// ==0||==2
        
        A[i][j]=2;
        if(0<i) dfs(A,i-1,j);
        if(i<A.size()-1)    dfs(A,i+1,j);
        if(0<j) dfs(A,i,j-1);
        if(j<A[0].size()-1) dfs(A,i,j+1);
        
        return ;
    }
};