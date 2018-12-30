/*
967. Numbers With Same Consecutive Differences

Related Topics: Dynamic Programming 

Test Cases:
3
7
2
1
1
0
2
0

Runtime: 8 ms
*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        // N in [1,9], K in [0,9] 
        vector<int> vc={1,2,3,4,5,6,7,8,9}, uc, vt={1,2,3,4,5,6,7,8,9}, ut;
        
        if(0<K){
            for( int i=1; i<N; i++){
                uc.clear();
                ut.clear();
                for( int j=0; j<vc.size(); j++){
                    if(vt[j]+K<10){
                        uc.push_back(vc[j]*10+vt[j]+K);
                        ut.push_back(vt[j]+K);
                    }
                    if(-1<vt[j]-K){
                        uc.push_back(vc[j]*10+vt[j]-K);
                        ut.push_back(vt[j]-K);
                    }
                }
                vc=uc;
                vt=ut;
            }
        }else{
            for( int i=1; i<N; i++){
                uc.clear();
                ut.clear();
                for( int j=0; j<vc.size(); j++){
                    uc.push_back(vc[j]*10+vt[j]);
                    ut.push_back(vt[j]);
                }
                vc=uc;
                vt=ut;
            }
        }
        if(N==1)    vc.push_back(0);
        
        return vc;
    }
};
