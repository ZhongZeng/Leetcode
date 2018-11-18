
/*
Leetcode 941. Valid Mountain Array

Test Cases:
[2,1]
[3,5,5]
[0,3,2,1]
[9,8,7,6,5,4,3,2,1,0]

Runtime: 40 ms

*/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)  return false;
        int i; 
        for( i=1; i<A.size(); i++){
            if(A[i-1]==A[i])    return false;
            else if(A[i]<A[i-1])   break;
        }
        
        if(i==1||i==A.size()) return false;
        
        for( ; i<A.size(); i++){
            if(A[i-1]<=A[i])    return false;
        }
        
        return true;
    }
};
