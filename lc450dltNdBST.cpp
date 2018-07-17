
/*
Leetcode 450. Delete Node in a BST

Companies 
Uber
Related Topics 
Tree 
Similar Questions 
Split BST

Test Cases:
[5,3,6,2,4,null,7]
3
[5,3,7,2,4,6,8]
7
[5,3,7,2,4,6,8]
5

Next challenges: Find Duplicate Subtrees, Maximum Depth of N-ary Tree, Search in a Binary Search Tree

Runtime: 20 ms
Your runtime beats 100.00 % of cpp submissions.

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return root;
        if(root->val==key)  return dlt( root );
        
        dfs( root, key);
        
        return root;
    }
    
    void dfs(TreeNode* tr, int key){
        if(tr->right){
            if(tr->right->val!=key){
                dfs( tr->right, key);
            }else{// delete tr->right 
                tr->right=dlt( tr->right );
                return ;                
            }
        }
        
        if(tr->left){
            if(tr->left->val!=key){
                dfs( tr->left, key);
            }else{// delete tr->left 
                tr->left=dlt( tr->left );
                return ;                
            }
        }
        
        return ;
    }
    
    TreeNode * dlt( TreeNode * tr){// delete node tr 
        if(tr->left){
            if(tr->right){
                TreeNode * tt=tr->left;
                if(tt->right){
                    while(tt->right->right) tt=tt->right;
                    tr->val=tt->right->val;
                    tt->right=tt->right->left;
                }else{
                    tr->val=tt->val;
                    tr->left=tt->left;// skip tr->left
                }
                return tr;
            }else{
                return tr->left;
            }
        }else{
            if(tr->right){
                return tr->right;
            }else{
                return NULL;
            }
        }
        return NULL;
    }
};
