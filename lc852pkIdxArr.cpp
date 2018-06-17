
/*

Leetcode 852. Peak Index in a Mountain Array

Weekly Contest 89  

Test Cases:
[0,1,0]
[0,2,1,0]

*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if(A.size()<1)  return 0;
        
        int i;
        
        for( i=1; i<A.size()-1; i++){
            if(A[i-1]<A[i]&&A[i+1]<A[i])    return i;
        }
            
        return i;
    }
};