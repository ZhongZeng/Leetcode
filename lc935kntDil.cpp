
/*
Leetcode 935. Knight Dialer

Test Cases: 1 2 3 4

Runtime: 60 ms

*/

class Solution {
public:
    int knightDialer(int N) {
        // DP; # moves ending at i in [0,9] 
        vector<vector<int>> vv={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4},{4,6}};
        vector<int> vc(10,1), vd(10,0);
        int rt=0;
        
        for( int i=1; i<N; i++){
            for( int j=0; j<10; j++)    vd[j]=0;
            
            for( int j=0; j<10; j++){// each j in vc 
                for( int k=0; k<vv[j].size(); k++)  vd[vv[j][k]]=(vd[vv[j][k]]+vc[j])%1000000007;
            }
            
            vc=vd;
        }
        
        for( int j=0; j<10; j++)    rt=(rt+vc[j])%1000000007;
        
        return rt;
    }
};