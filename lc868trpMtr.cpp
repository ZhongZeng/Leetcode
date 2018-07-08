
/*
868. Transpose Matrix

Test Cases:
[[1,2,3],[4,5,6],[7,8,9]]
[[1,2,3],[4,5,6]]
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> vv;
        if(A.size()<1||A[0].size()<1)   return vv;
        
        for( int i=0; i<A[0].size(); i++){
            vector<int> vc;
            for( int j=0; j<A.size(); j++)  vc.push_back(A[j][i]);
            vv.push_back(vc);
        }
        
        return vv;
    }
};
