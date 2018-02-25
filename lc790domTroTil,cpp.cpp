
/*
Leetcode 790. Domino and Tromino Tiling

Test Cases:
2
3
9
20
30
890

Runtime: 3 ms

*/

class Solution {
public:
    int numTilings(int N) {
        // DP
        if(N<1) return 0;
        else if(N<2)    return 1;
        
        vector<int> v1={0,0,1},v2={1,1,2},v3(3,0);
        // xx x  x  xx xy 
        // x  xx x  yy xy
        for(int i=2; i<N; i++){
            v3[0]=(v2[1]+v1[2])%1000000007;
            v3[1]=(v2[0]+v1[2])%1000000007;
            v3[2]=(((v2[0]+v2[1])%1000000007)+((v2[2]+v1[2])%1000000007))%1000000007;
            
            copyVc(v2, v1);
            copyVc(v3, v2);
        }
        
        return v2[2];
    }
    
    void copyVc(vector<int>& v1, vector<int>& v2){// v2=v1
        for(int i=0; i<3; i++)  v2[i]=v1[i];
        return ;
    }
};