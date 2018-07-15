
/*
Leetcode 869. Reordered Power of 2

Test Cases:
1
20
10
16
24

Runtime: 136 ms

*/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        // backtrack, don't over think it, O(log(N)) should be fast
        vector<int> vc;
        while(N!=0){
            vc.push_back(N%10);
            N=N/10;
        }
        
        return dfs( vc, 0);
    }
    
    bool dfs(vector<int>& vc, int i){
        if(i==vc.size()){
            int sum=0;
            for( int i=0; i<vc.size(); i++) sum=sum*10+vc[i];
            while(1<sum){
                if((sum>>1)<<1!=sum)    return false;
                else    sum=sum>>1;
            }
            return true;
        }
        
        for( int j=i, t; j<vc.size(); j++ ){
            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;
            
            if(i!=0||vc[i]!=0){
                if(dfs(vc,i+1)) return true;
            }
            
            t=vc[i];
            vc[i]=vc[j];
            vc[j]=t;            
        }
        
        return false;
    }
};
