
/*
Leetcode 285. Inorder Successor in BST

Companies 
Facebook, Microsoft, Pocket Gems 
Related Topics 
Tree 
Similar Questions 
Binary Tree Inorder Traversal, Binary Search Tree Iterator

Next challenges: Unique Binary Search Trees II, 
Count Univalue Subtrees, Find Duplicate Subtrees

Test Cases:
[2,null,3]
[3,1,4,null,2]

Runtime: 28 ms
Your runtime beats 23.25 % of cpp submissions.

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // next larger node; DFS in-order traversal, O(h) time
        if(!root)   return root;
        if(!p)  return p;
        TreeNode * rt=NULL;
        if(p->right){
            for( rt=p->right; rt->left!=NULL; rt=rt->left){}
            return rt;
        }else{// DFS,  pre-order traversal 
            while(true){
                if(p->val<root->val){
                    rt=root;
                    if(root->left!=NULL)    root=root->left;
                    else    break;
                }else if(root->val<p->val){
                    if(root->right!=NULL)   root=root->right;
                    else    break;
                }else{
                    break;
                }
            }
            return rt;
        }
    }
};