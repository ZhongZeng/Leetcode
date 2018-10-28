
/*
Leetcode 930. Binary Subarrays With Sum

Runtime: 16 ms

*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        // O(n) time 
        int rt=0;
        vector<int> vc={-1};
        
        for( int i=0; i<A.size(); i++){
            if(A[i]!=0) vc.push_back(i);
        }
        vc.push_back(A.size());
        
        if(S!=0){
            for( int i=1, j=S; j<vc.size()-1; i++, j++){// sum(A[i,j])==S
                rt+=(vc[i]-vc[i-1])*(vc[j+1]-vc[j]);// previaling&trailing zeros
            }
        }else{
            for( int i=1; i<vc.size(); i++){
                rt+=(vc[i]-vc[i-1]-1)*(vc[i]-vc[i-1])/2;// len*(len+1)/2;
            }
        }
        
        return rt;
    }
};
