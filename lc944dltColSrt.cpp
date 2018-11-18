
/*
Leetcode 944. Delete Columns to Make Sorted

Test Cases:
["cba","daf","ghi"]
["a","b"]
["zyx","wvu","tsr"]

Runtime: 48 ms

*/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // remove all unsorted columns
        if(A.size()<2||A[0].size()<1)   return 0;
        int rt=0;
        
        for( int i=0; i<A[0].size(); i++){
            for( int j=1; j<A.size(); j++){
                if(A[j][i]<A[j-1][i]){
                    rt++;
                    break;
                }
            }
        }
        
        return rt;
    }
};