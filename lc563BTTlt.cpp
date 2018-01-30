
/*
Leetcode 563. Binary Tree Tilt

Related Topics 
Tree

Next challenges: Invert Binary Tree, 
Closest Binary Search Tree Value, Largest BST Subtree

Test Cases:
[1,2,3]
[1,2,3,4,1,null,8]

Runtime: 21 ms
Your runtime beats 30.10 % of cpp submissions. 

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
    int findTilt(TreeNode* root) {
        // post-order traversal
        int sum=0;
        findTilt(root, sum);
        return sum;
    }
    
    int findTilt(TreeNode* root, int& sum){
        if(!root)   return 0;
        
        int r, l;
        r=findTilt(root->right, sum);
        l=findTilt(root->left, sum);
        
        sum+=r<l?l-r:r-l;
            
        return r+l+root->val;
    }
    
};
