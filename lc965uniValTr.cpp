/*
965. Univalued Binary Tree

Related Topics: Tree 

Test Cases:
[1,1,1,1,1,null,1]
[1,1,1,1,1,null,2]

Runtime: 4 ms
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
    bool isUnivalTree(TreeNode* root) {
        if(!root)   return true;
        int v=root->val;
        return dfs(root,v);
    }
    
    bool dfs(TreeNode * tr, int v){
        if(!tr) return true;
        if(tr->val!=v)  return false;
        if(!dfs(tr->left,v))  return false;
        if(!dfs(tr->right,v)) return false;
        return true;
    }
};