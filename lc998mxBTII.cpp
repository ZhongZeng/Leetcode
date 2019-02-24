/*
998. Maximum Binary Tree II

Related Topics: Tree 

Test Cases:
[4,1,3,null,null,2]
5
[5,2,4,null,1]
3
[5,2,3,null,1]
4

Runtime: 12 ms
Memory Usage: 11.6 MB
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode * tr, * pr, * nd=new TreeNode(val);
        
        for( tr=root; tr!=NULL&&val<tr->val; pr=tr, tr=tr->right ){}
        
        if(tr!=root){
            nd->left=pr->right;
            pr->right=nd;
        }else{// val > root->val 
            nd->left=root;
            return nd;
        }
        
        return root;
    }
};