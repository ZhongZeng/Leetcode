


/*
Leetcode 110. Balanced Binary Tree

Related Topics 
Tree, Depth-first Search 
Similar Questions 
Maximum Depth of Binary Tree

Test Cases:
[]
[1,2,3]
[1,2,3,null,4,5,null,null,6]

Runtime: 10 ms
Your runtime beats 23.90 % of cpp submissions.

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
    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        int a=isBalanced(root, 0);
        return a!=-2;
    }
    
    int isBalanced(TreeNode* root, int d){
        if(!root)   return d;
        
        int l=isBalanced(root->left, d+1),r=isBalanced(root->right, d+1);
        
        if(r<l) return 1<l-r?-2:l;
        else if(l<r)    return 1<r-l?-2:r;
        else    return l;
    }
};

