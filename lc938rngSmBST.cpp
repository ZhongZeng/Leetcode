
/*
Leetcode 938. Range Sum of BST
Medium

Test Cases:
[10,5,15,3,7,null,18]
7
15
[10,5,15,3,7,13,18,1,null,6]
6
10

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        return dfs( root, L, R);
    }
    
    int dfs(TreeNode * tr, int& L, int& R){
        if(!tr) return 0;
        
        int rt=0;
        if(L<=tr->val&&tr->val<=R)  rt+=tr->val;
        if(L<=tr->val)   rt+=dfs( tr->left, L, R);
        if(tr->val<=R)   rt+=dfs( tr->right, L, R);
        
        return rt;
    }
};