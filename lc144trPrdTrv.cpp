

/*
Leetcode 144. Binary Tree Preorder Traversal

Related Topics 
Stack, Tree
Similar Questions 
Binary Tree Inorder Traversal, 
Verify Preorder Sequence in Binary Search Tree

Next challenges: Binary Tree Inorder Traversal, 
Verify Preorder Sequence in Binary Search Tree

Test Cases:
[1,null,2,3]
[1,2,3,4,5,null,7]

Runtime: 3 ms
Your runtime beats 0.58 % of cpp submissions. which is within majority. 

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
    vector<int> preorderTraversal(TreeNode* root) {
		// iterative 
        vector<int> rt;
        if(!root)   return rt;
        TreeNode* tr;
        vector<TreeNode*> vc;
        vc.push_back(root);
        
        while(!vc.empty()){
            tr=vc.back();
            rt.push_back(tr->val);
            vc.pop_back();
            if(tr->right)   vc.push_back(tr->right);
            if(tr->left)    vc.push_back(tr->left);
        }
        
        return rt;
    }
};


/* 
// Runtime: 3 ms
// Your runtime beats 0.58 % of cpp submissions. which is within majority. 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		// recursion
        vector<int> vc;
        if(!root)   return vc;
        preorderTraversal(root, vc);
        return vc;
    }
    
    void preorderTraversal(TreeNode* root, vector<int>& vc){
        vc.push_back(root->val);
        if(root->left)  preorderTraversal(root->left, vc);
        if(root->right) preorderTraversal(root->right, vc);
        return ;
    }
};
*/
