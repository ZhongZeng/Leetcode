
/*
Leetcode 329. Longest Increasing Path in a Matrix

Companies 
Google
Related Topics 
Depth-first Search, Topological Sort, Memorization 

Next challenges: Zuma Game, Increasing Subsequences, Freedom Trail

Test Case:
[[9,9,4],[6,6,8],[2,1,1]]

Runtime: 43 ms
Your runtime beats 47.81 % of cpp submissions.

*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // O(n*m) time&space; DFS(post-order), DP(Memorization) 
        if(matrix.size()<1||matrix[0].size()<1) return 0;
        int mx=0;
        vector<int> vc(matrix[0].size(), -1);
        vector<vector<int>> va(matrix.size(), vc), vd(matrix.size(), vc);
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                DFSInc( i, j, va, matrix);
                //cout<<va[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                DFSDec( i, j, vd, matrix);
                //cout<<vd[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(mx<va[i][j]+vd[i][j])    mx=va[i][j]+vd[i][j];
            }
        }        
        
        return mx+1;
    }
    
    int DFSInc(int i, int j, vector<vector<int>>& va, vector<vector<int>>& matrix){
        // ascending, topological order guranteed 
        if(va[i][j]==-1){
            va[i][j]=0;
            int t;
            if(0<i&&matrix[i][j]<matrix[i-1][j]){
                t=DFSInc(i-1, j, va, matrix);
                if(va[i][j]<t)  va[i][j]=t;
            }

            if(0<j&&matrix[i][j]<matrix[i][j-1]){
                t=DFSInc(i, j-1, va, matrix);
                if(va[i][j]<t)  va[i][j]=t;
            }

            if(i<matrix.size()-1&&matrix[i][j]<matrix[i+1][j]){
                t=DFSInc(i+1, j, va, matrix);
                if(va[i][j]<t)  va[i][j]=t;
            }
            
            if(j<matrix[0].size()-1&&matrix[i][j]<matrix[i][j+1]){
                t=DFSInc(i, j+1, va, matrix);
                if(va[i][j]<t)  va[i][j]=t;
            }
        }
        
        return va[i][j]+1;
    }
    
    int DFSDec(int i, int j, vector<vector<int>>& vd, vector<vector<int>>& matrix){
        // descending, topological order guranteed 
        if(vd[i][j]==-1){
            vd[i][j]=0;
            int t;
            if(0<i&&matrix[i][j]>matrix[i-1][j]){
                t=DFSDec(i-1, j, vd, matrix);
                if(vd[i][j]<t)  vd[i][j]=t;
            }

            if(0<j&&matrix[i][j]>matrix[i][j-1]){
                t=DFSDec(i, j-1, vd, matrix);
                if(vd[i][j]<t)  vd[i][j]=t;
            }

            if(i<matrix.size()-1&&matrix[i][j]>matrix[i+1][j]){
                t=DFSDec(i+1, j, vd, matrix);
                if(vd[i][j]<t)  vd[i][j]=t;
            }
            
            if(j<matrix[0].size()-1&&matrix[i][j]>matrix[i][j+1]){
                t=DFSDec(i, j+1, vd, matrix);
                if(vd[i][j]<t)  vd[i][j]=t;
            }
        }
        
        return vd[i][j]+1;
    }    
};
