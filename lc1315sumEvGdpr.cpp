/*
1315. Sum of Nodes with Even-Valued Grandparent

Company	Amazon
Related Topics	Tree, Depth-first Search 

Test Case:
[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]

Runtime: 44 ms, faster than 50.00% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
Memory Usage: 31.3 MB, less than 100.00% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.

Next challenges: Concatenated Words, Deepest Leaves Sum, 
Find Elements in a Contaminated Binary Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        // DFS, O(n) time, O(h) space 
        int sum=0;
        dfs( sum, root, NULL, NULL);
        return sum;
    }
    
protected:
    void dfs( int & sum, TreeNode* th, TreeNode* pr, TreeNode* gp){// pre-order 
        if(!th) return ;//  null node 
        if(gp&&gp->val%2==0)    sum+=th->val;
        
        dfs( sum, th->left, th, pr);
        dfs( sum, th->right, th, pr);
        
        return ;
    }
};