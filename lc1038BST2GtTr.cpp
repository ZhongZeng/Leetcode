/*
1038. Binary Search Tree to Greater Sum Tree

Companies	Amazon
Related Topics	Binary Search Tree 

Test Cases:
[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]

Runtime: 4 ms
Memory Usage: 9.3 MB

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
    TreeNode* bstToGst(TreeNode* root) {
        // O(n) time, O(1) space
        int sum=sumDFS(root), cur=0;
        modDFS(root, sum, cur);
        return root;
    }
    
protected:
    int sumDFS(TreeNode *tr){
        if(tr==NULL)    return 0;
        return tr->val+sumDFS(tr->left)+sumDFS(tr->right);
    }
    
    void modDFS(TreeNode *tr, int& sum, int& cur){// in-order DFS
        if(tr==NULL)    return ;
        modDFS(tr->left, sum, cur);
        cur+=tr->val;
        tr->val+=sum-cur;//tr->val += all values>tr->val
        modDFS(tr->right, sum, cur);
        return ;
    }
};