

/*
Leetcode 98. Validate Binary Search Tree

Related Topics 
Tree, Depth-first Search 
Similar Questions 
Binary Tree Inorder Traversal, Find Mode in Binary Search Tree

Test Case:
[2,1,3]
[1,2,3]
[1,1]
[2147483647]

Runtime: 15 ms
Your runtime beats 11.61 % of cpp submissions.

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
    bool isValidBST(TreeNode* root) {
        // <> no == in this BST 
        if(!root)   return true;
        
        return isValidBST(root->left, 0, root->val, 0)&&isValidBST(root->right, root->val, 0, 1);
    }

protected:    
    bool isValidBST(TreeNode* root, int mn, int mx, int i) {
        // i:0-negative infinite, 1-positive infinite, 2-limited on both sides
        if(!root)   return true;
        switch(i){
            case 0: 
                return root->val<mx&&isValidBST(root->left, mn, root->val, 0)&&isValidBST(root->right, root->val, mx, 2);
            case 1:
                return mn<root->val&&isValidBST(root->left, mn, root->val, 2)&&isValidBST(root->right, root->val, mx, 1);
            case 2:
                return root->val<mx&&mn<root->val&&
                    isValidBST(root->left, mn, root->val, 2)&&isValidBST(root->right, root->val, mx, 2);
        }
    }
    
};

/*
// Wrong answer. There are test cases designed to fail this solution. 

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // <> no == in this BST 
        if(!root)   return true;
        int mn, mx;
        TreeNode* tr;
        for(tr=root; tr->left; tr=tr->left){}
        mn=tr->val-1;    
        
        for(tr=root; tr->right; tr=tr->right){}
        mx=tr->val+1;
        
        return isValidBST(root, mn, mx);
    }

protected:    
    bool isValidBST(TreeNode* root, int mn, int mx) {
        if(!root)   return true;
        if(mn<root->val&&root->val<mx){
            return isValidBST(root->left, mn, root->val)&&isValidBST(root->right, root->val, mx);
        }else{
            return false;
            
        }
    }
    
};

*/

/*
// Wrong answer. Equal is not allowed. 

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        int mn, mx;
        TreeNode* tr;
        for(tr=root; tr->left; tr=tr->left){}
        mn=tr->val;    
        
        for(tr=root; tr->right; tr=tr->right){}
        mx=tr->val;
        
        return isValidBST(root, mn, mx);
    }

protected:    
    bool isValidBST(TreeNode* root, int mn, int mx) {
        if(!root)   return true;
        if(root->val<mn||mx<root->val){
            return false;
        }else{
            return isValidBST(root->left, mn, root->val)&&isValidBST(root->right, root->val, mx);
        }
    }
    
};

*/
