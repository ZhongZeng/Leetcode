
/*
Leetcode 775. Global and Local Inversions

Related Topics 
Array, Math 

Test Cases:
[0]
[1,0,2,3]
[2,0,3,1]
[0,1,2]
[2,0,1]
[2,1,0]
[1,0,4,5,3,2]
[2,4,1,0,3]

Runtime: 67 ms

*/

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        // This is easier than I thought. No need to compute # global inversion
        // O(n) time
		// If diff > 1, global inversion > local inversion. 
        for(int i=0; i<A.size(); i++){
            if(A[i]-i<-1||1<A[i]-i) return false;
        }
        
        return true;
    }
};
