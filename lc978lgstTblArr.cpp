/*
978. Longest Turbulent Subarray

Related Topics 
Array 

Test Case:
[170,59,129,54,5,98,129,37,58,193]

Runtime: 112 ms

*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        // array, not need DP
        // Traverse the array twice. Once for longest turbulent subarray for scenario 1, the other time for scenario 2. 
        if(A.size()<1)  return 0;
        int i, o=1, mx=1;// longest length of scenario 1&2 
        
        for( o=1, i=0; i+1<A.size(); i++){
            if(i%2==1){
                if(A[i]>A[i+1]) o++;
                else    o=1;
            }else{
                if(A[i]<A[i+1]) o++;
                else    o=1;
            }
            mx=mx<o?o:mx;
        }
        
        for( o=1, i=0; i+1<A.size(); i++){
            if(i%2==0){
                if(A[i]>A[i+1]) o++;
                else    o=1;
            }else{
                if(A[i]<A[i+1]) o++;
                else    o=1;
            }
            mx=mx<o?o:mx;
        }
        
        return mx;
    }
};
