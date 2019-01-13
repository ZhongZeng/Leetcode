/*
976. Largest Perimeter Triangle

Related Topics: Array, Math 

Test Cases:
[2,1,2]
[3,2,3,4]
[3,6,2,3]

Runtime: 52 ms
Your runtime beats 100.00 % of cpp submissions.
*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        // greedy; O(n*log(n)) time; largest 3 ints that can form a triangle
        sort(A.begin(),A.end());// O(n*log(n)) time 
        
        for( int i=A.size()-1; 1<i; i--){// O(n) time 
            // if largest 3 edges can't form a triangle, so can't the largest w/ any other
            if(A[i-2]+A[i-1]>A[i])  return A[i-2]+A[i-1]+A[i];
        }
        
        return 0;
    }
};