
/*
951. Flip Equivalent Binary Trees

Related Topics: Tree 

Test Cases:
[1,2,null]
[1,null,2]
[1,2,3,4,5,6,null,null,null,7,8]
[1,3,2,null,6,4,5,null,null,null,null,8,7]

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // not same as sysmetic tree; DFS, O(m+n) time 
        
        return dfs( root1, root2);
    }
    
    bool dfs(TreeNode* root1, TreeNode* root2){
        if(!root1)  return !root2;
        if(!root2)  return false;
        //cout<<root1->val<<" "<<root2->val<<"; ";
        
        if(root1->val!=root2->val)  return false;
        
        return dfs(root1->left, root2->right)&&dfs(root1->right, root2->left)
             ||dfs(root1->right, root2->right)&&dfs(root1->left, root2->left);
    }
};