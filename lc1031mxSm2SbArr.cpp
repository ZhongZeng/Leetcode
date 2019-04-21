/*
1031. Maximum Sum of Two Non-Overlapping Subarrays

Related Topics	Array

Test Cases:
[0,6,5,2,2,5,1,9,4]
1
2
[3,8,1,3,2,1,8,9,0]
3
2
[2,1,5,6,0,9,5,0,3,8]
4
3

Runtime: 8 ms
Memory Usage: 8.8 MB
Your runtime beats 100.00 % of cpp submissions.
*/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        // O(n*n) time; L+M<=A.size() in [1,1000]; A[i] in [0,1000]
        int mx=0, cs, ct;
        vector<int> vs={0};// vc[i]=sum of [0,i) 
        for( int i=0; i<A.size(); i++)  vs.push_back(vs.back()+A[i]);
        
        for( int i=0; i+L<=A.size(); i++){
            cs=vs[i+L]-vs[i];
            for( int j=0; j+M<=i; j++){
                ct=cs+vs[j+M]-vs[j];
                if(mx<ct)   mx=ct;
            }
            
            for( int j=i+L; j+M<=A.size(); j++){
                ct=cs+vs[j+M]-vs[j];
                if(mx<ct)   mx=ct;
            }
        }
        
        return mx;
    }
};