
/*
Leetcode 814. Binary Tree Pruning

Test Case:
[1,null,0,0,1]
[1,0,1,0,0,0,1]
[1,1,0,1,1,0,1,0]

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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)   return root;
        
        if(dfs(root))   return root->val!=1?NULL:root;
        else    return root;
    }
    
    bool dfs(TreeNode * tr){// not containing 1
        // DFS, post-order traversal 
        if(!tr) return true;
        //cout<<tr->val<<" ";
        
        if(tr->right==NULL||dfs(tr->right)){
            tr->right=NULL;
            if(tr->left==NULL||dfs(tr->left)){
                tr->left=NULL;
                return tr->val!=1;
            }else{
                return false;
            }
        }else{
            if(tr->left==NULL||dfs(tr->left))   tr->left=NULL;
            return false;
        }
    }
};