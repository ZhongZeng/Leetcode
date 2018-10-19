
/*
Leetcode 922. Sort Array By Parity II

Runtime: 68 ms
Your runtime beats 92.81 % of cpp submissions.

Next challenges: Concatenated Words, Remove 9, Shortest Path Visiting All Nodes

*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        // A half even, half odd
        vector<int> rt, od ,ev;
        
        for( int i=0; i<A.size(); i++){
            if(A[i]%2==1)   od.push_back(A[i]);
            else    ev.push_back(A[i]);
        }
        
        for( int i=0; i<od.size(); i++){
            rt.push_back(ev[i]);
            rt.push_back(od[i]);
        }
        
        return rt;
    }
};