

/*
Leetcode 576. Out of Boundary Paths

Companies 
Baidu 
Related Topics 
Dynamic Programming, Depth-first Search 
Similar Questions 
Knight Probability in Chessboard

Next challenges: Knight Probability in Chessboard

Test Cases:
2
2
2
0
0
3
6
8
0
4

Runtime: 6 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        // DP+BFS, O(m*n*N); m rows, n columns; record # of paths to this element
        int sum=0;
        vector<int> vc(n,0);
        vector<vector<int>> vv(m,vc), uv(m,vc);
        vv[i][j]=1;
        
        for( int i=0; i<N; i++){
            for( int j=0; j<m; j++) for( int k=0; k<n; k++) uv[j][k]=0;
            
            for( int j=0; j<m; j++){
                for( int k=0; k<n; k++){
                    //cout<<i<<":"<<j<<", "<<k<<endl;
                    if(vv[j][k]!=0){
                        if(0<j) uv[j-1][k]=(uv[j-1][k]+vv[j][k])%1000000007;
                        else    sum=(sum+vv[j][k])%1000000007;
                        if(0<k) uv[j][k-1]=(uv[j][k-1]+vv[j][k])%1000000007;
                        else    sum=(sum+vv[j][k])%1000000007;
                        if(j<m-1)   uv[j+1][k]=(uv[j+1][k]+vv[j][k])%1000000007;
                        else    sum=(sum+vv[j][k])%1000000007;
                        if(k<n-1)   uv[j][k+1]=(uv[j][k+1]+vv[j][k])%1000000007;
                        else    sum=(sum+vv[j][k])%1000000007;
                    }
                }
            }
            vv=uv;
        }
        
        return sum;
    }
};
