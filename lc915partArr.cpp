/*
915. Partition Array into Disjoint Intervals

Companies	Grab
Related Topics	Array 

Test Cased:
[5,0,3,8,6]
[1,1,1,0,6,12]
[1,1]

Next challenges: Median of Two Sorted Arrays, Construct Binary Tree from Inorder and Postorder Traversal, Reveal Cards In Increasing Order

Runtime: 44 ms	Your runtime beats 87.74 % of cpp submissions.
Memory Usage: 11 MB	Your memory usage beats 72.82 % of cpp submissions.

*/

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        // O(n) time, O(1) space, greedy, array; all left[i]<=right[j], max(left)<=min(right); 1 partition guranteed 
        if(A.size()<1)  return 0;
        int rt=0, ml=A[0], mx=A[0];//  ml: max in left[0,rt]; mx: max in [0,i] 
        for( int i=0; i<A.size(); i++){
            mx=mx<A[i]?A[i]:mx;
            if(A[i]<ml){
                ml=mx;
                rt=i;
            }
        }
        return rt+1;
    }
};