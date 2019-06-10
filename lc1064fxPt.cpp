/*
1064. Fixed Point

Companies	Uber
Related Topics	Array, Binary Search

Test Case:
[-10,-5,0,3,7]

Runtime: 12 ms	Your runtime beats 97.03 % of cpp submissions.
Memory Usage: 9.6 MB	

Next challenges: Data Stream as Disjoint Intervals, Maximum Average Subarray II, Super Egg Drop
*/

class Solution {
public:
    int fixedPoint(vector<int>& A) {
        // this is a dumb problem
        int i;
        for( i=0; i<A.size(); i++){
            if(A[i]==i) break;
        }
        return i!=A.size()?i:-1;
    }
};