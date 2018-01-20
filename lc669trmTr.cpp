
/*
Leetcode 669. Trim a Binary Search Tree

Related Topics 
Tree

Next challenges: Largest BST Subtree, 
Path Sum III, Closest Leaf in a Binary Tree

Test Cases:
[1,0,2]
1
2
[1,null,2]
2
4
[3,1,4,null,2]
3
4
[45,30,46,10,36,null,49,8,24,34,42,48,null,4,9,14,25,31,35,41,43,47,null,0,6,null,null,11,20,null,28,null,33,null,null,37,null,null,44,null,null,null,1,5,7,null,12,19,21,26,29,32,null,null,38,null,null,null,3,null,null,null,null,null,13,18,null,null,22,null,27,null,null,null,null,null,39,2,null,null,null,15,null,null,23,null,null,null,40,null,null,null,16,null,null,null,null,null,17]
32
44

Runtime: 17 ms
Your runtime beats 33.00 % of cpp submissions.

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        // BFS
        TreeNode * tr;
        queue<TreeNode *> qu;
        while(root){
            if(root->val<L){
                root=root->right;
            }else{
                if(root&&R<root->val)   root=root->left;
                else break;
            }
        }
        if(root)    qu.push(root);
        
        while(!qu.empty()){
            tr=qu.front();
            qu.pop();
            while(tr->left&&tr->left->val<L)   tr->left=tr->left->right;
            if(tr->left)    qu.push(tr->left);
            while(tr->right&&R<tr->right->val) tr->right=tr->right->left;
            if(tr->right)   qu.push(tr->right);
        }
        
        return root;
    }
};
