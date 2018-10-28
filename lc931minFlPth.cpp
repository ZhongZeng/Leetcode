

/*
Leetcode 931. Minimum Falling Path Sum

Test Cases:
[[1,2,3],[4,5,6],[7,8,9]]
[[1]]
[[-80,-13,22],[83,94,-5],[73,-48,61]]

*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        // DP, O(m*n) time; square A
        if( A.size()==1 )   return A[0][0];
        
        int rt, min;
        vector<int> vc;
        vector<vector<int>> vv(A.size(),vc);
        vv[0]=A[0];
        
        for( int i=1; i<vv.size(); i++){
            min=vv[i-1][0]<vv[i-1][1]?vv[i-1][0]:vv[i-1][1];
            vv[i].push_back(A[i][0]+min);
            for( int j=1; j<A[i].size()-1; j++){
                min=vv[i-1][j];
                if(vv[i-1][j-1]<min)  min=vv[i-1][j-1];
                if(vv[i-1][j+1]<min)  min=vv[i-1][j+1];
                vv[i].push_back(A[i][j]+min);
                //cout<<i<<","<<j<<":"<<min<<" ";
            }
            min=vv[i-1][A.size()-2]<vv[i-1].back()?vv[i-1][A.size()-2]:vv[i-1].back();
            vv[i].push_back(A[i].back()+min);
        }
        
        rt=vv.back()[0];
        for( int i=0; i<vv.back().size(); i++){
            if(vv.back()[i]<rt) rt=vv.back()[i];
        }
        
        return rt;
    }
};
