

/*
Leetcode 230. Kth Smallest Element in a BST

Related Topics 
Binary Search, Tree 
Similar Questions 
Binary Tree Inorder Traversal, Second Minimum Node In a Binary Tree

Test Cases:
[1]
1
[6,2,9,1,3,7,11]
3

Runtime: 15 ms
Your runtime beats 61.11 % of cpp submissions.

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
    int kthSmallest(TreeNode* root, int k) {
        // DFS, in-order traversal
        if(!root)   return 0;
        vector<int> vc;
        
        if(kth(root, k, vc))    return vc.back();// always true
        else    return -1;
    }
                           
    bool kth(TreeNode* root, int k, vector<int>& vc){
        if(!root)   return false;
        
        if(kth(root->left, k, vc))  return true;
        vc.push_back(root->val);
        if(vc.size()==k)    return true;
        if(kth(root->right, k, vc)) return true;
            
        return false;
    }
                           
};
