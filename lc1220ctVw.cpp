/*
1220. Count Vowels Permutation

Companies	C3.ai
Related Topics	Dynamic Programming

Test Cases:
1
2
5

Runtime: 48 ms
Memory Usage: 20.5 MB
*/

class Solution {
public:
    int countVowelPermutation(int n) {
        // DP, O(n) time, O(1) space; medium
        int rt=0;
        vector<int> vc(5,1);// a, e, i, o, u
        
        for( int i=2; i<=n; i++){
            vector<int> vd(5,0);
            vd[0]=(1000000007<vc[1]+vc[2]?vc[1]+vc[2]-1000000007:vc[1]+vc[2])+vc[4];// e,i,u -> a 
            vd[1]=vc[0]+vc[2];// a,i -> e
            vd[2]=vc[1]+vc[3];// e,o -> i
            vd[3]=vc[2];// i -> o
            vd[4]=vc[2]+vc[3];// i,o -> u
            vc=vd;
            for( int j=0; j<vc.size(); j++) vc[j]=1000000007<vc[j]?vc[j]-1000000007:vc[j];
        }
        
        for( int i=0; i<vc.size(); i++) rt=(rt+vc[i])%1000000007;
        
        return rt;
    }
};