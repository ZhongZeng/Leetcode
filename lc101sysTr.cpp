

/*
Leetcode 101. Symmetric Tree

Related Topics 
Tree, Depth-first Search, Breadth-first Search

Test Cases:
[1,2,2,3,4,4,3]
[]

Next challenges: Convert Sorted List to Binary Search Tree, 
Walls and Gates, Longest Univalue Path

Runtime: 6 ms
Your runtime beats 12.12 % of cpp submissions.

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
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        return isMirror(root->left,root->right);
    }

protected:    
    bool isMirror(TreeNode* & r1, TreeNode* & r2){
        // recursive
        if(!r1)    return !r2;
        if(!r2)    return !r1;
        //cout<<r1->val<<" "<<r2->val<<endl;
        if(r1->val!=r2->val)    return false;
        else    return isMirror(r1->left,r2->right)&&isMirror(r1->right,r2->left);
    }
    
};
