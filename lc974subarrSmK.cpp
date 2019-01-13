/*
974. Subarray Sums Divisible by K

Related Topics: Array 

Test Cases: 
[1,2,3]
6
[4,5,0,-2,-3,1]
5

Runtime: 2264 ms
better use hash table or prefix sum 
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        // DP, O(n*K) time, O(K) space; K in[2,1000]
        int sum=0, r;
        vector<int> vc(K,0);// vc[i] = # subarray ending@current node w/ sum%K==i 
        
        for(int i=0; i<A.size(); i++){
            r=A[i]%K;// r in (-K,K) 
            vc=shiftVector(vc, r<0?r+K:r);
            sum+=vc[0];
        }
        
        return sum;
    }
protected:
    vector<int> shiftVector( vector<int> vc, int r){// r in [0,vc.size()) 
        vector<int> vd(vc.size(),0);
        for(int i=0; i<vc.size(); i++)  vd[vc.size()<=i+r?i+r-vc.size():i+r]=vc[i];
        vd[r]+=1;
        return vd;
    }
};