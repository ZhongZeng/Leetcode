
/*
Leetcode 156. Binary Tree Upside Down

Companies 
LinkedIn
Related Topics 
Tree 
Similar Questions 
Reverse Linked List

Next challenges: Closest Binary Search Tree Value II, 
Serialize and Deserialize BST, Boundary of Binary Tree

Test Case:
[1,2,3,4,5]

Runtime: 4 ms
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        // DFS; Don't over-complicate this problem. 
        // left child->root; right child->left child; root-> right child
        if(!root)   return root;
        TreeNode * rt, * tr=root;
        vector<TreeNode*> vt;
        
        while(tr){
            vt.push_back(tr);
            tr=tr->left;
        }
        
        rt=vt.back();
        
        for(int i=vt.size()-1; 0<i; i--){
            vt[i]->right=vt[i-1];
            vt[i]->left=vt[i-1]->right;
        }
        vt[0]->left=NULL;
        vt[0]->right=NULL;
        
        return rt;
    }
};
