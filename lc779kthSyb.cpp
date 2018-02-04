
/*
779. K-th Symbol in Grammar

Weekly Contest 70  

Test Cases:
1
1
2
1
2
2
4
5

*/


class Solution {
public:
    int kthGrammar(int N, int K) {
        // Binary Search
        int e=0;
        vector<int> d, r;
        
        K=K-1;
        for(int i=1; i<N; i++){
            r.push_back(K%2);
            K=K/2;
        }
        
        for(int i=N-2; -1<i; i--){
            e=r[i]^e?1:0;
        }
        
        return e;
    }
};
