
/*961. N-Repeated Element in Size 2N Array

Related Topics: Hash Table 

Test Case: [1,2,3,3]

Runtime: 40 ms

*/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        // O(n) time
        unordered_set<int> us;
        unordered_set<int>::iterator usi;
        for( int i=0; i<A.size(); i++){
            usi=us.find(A[i]);
            if(usi!=us.end())   return A[i];
            else    us.emplace(A[i]);
        }
        return -1;
    }
};
