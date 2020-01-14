/*
1314. Matrix Block Sum

Companies	Google
Related Topics	Dynamic Programming 

Runtime: 20 ms, faster than 99.51% of C++ online submissions for Matrix Block Sum.
Memory Usage: 12.7 MB, less than 100.00% of C++ online submissions for Matrix Block Sum.
Runtime: 32 ms, faster than 56.92% of C++ online submissions for Matrix Block Sum.
Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Matrix Block Sum.

Next challenges:
Frog Jump, Push Dominoes, Shortest Way to Form String
*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        // O(n*m) space&time, array 
        vector<vector<int>> sum, rt;// sum: sum of elements in mat [0,0] to [i-1,j-1] 
        vector<int> vc(mat[0].size()+1, 0);
        sum.push_back(vc);
        
        for( int i=0; i<mat.size(); i++){
            vector<int> vc={0};
            for( int j=0; j<mat[i].size(); j++)
                vc.push_back(vc.back()+sum.back()[vc.size()]-sum.back()[vc.size()-1]+mat[i][j]);
            sum.push_back(vc);
        }
        
        for( int i=0; i<mat.size(); i++){
            vector<int> vc;
            for( int j=0; j<mat[i].size(); j++){
                int r0=-1<i-K?i-K:0, r1=i+K+1<sum.size()?i+K+1:sum.size()-1, c0=-1<j-K?j-K:0, c1=j+K+1<sum[0].size()?j+K+1:sum[0].size()-1;
                vc.push_back( sum[r1][c1]+sum[r0][c0]-sum[r0][c1]-sum[r1][c0]);
            }
            rt.push_back(vc);
        }
        
        return rt;
    }
};