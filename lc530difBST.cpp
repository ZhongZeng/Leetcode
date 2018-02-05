
/*
Leetcode 530. Minimum Absolute Difference in BST

Related Topics 
Binary Search Tree 
Similar Questions 
K-diff Pairs in an Array

Next challenges: Data Stream as Disjoint Intervals, K Empty Slots, Falling Squares

Test Cases:
[1,null,3,2]
[14,4,19,1,6]

Runtime: 19 ms
Your runtime beats 24.60 % of cpp submissions.

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
    int getMinimumDifference(TreeNode* root) {
        // O(n) time; DFS, in-order traversal, recursion
        int lt, rg, df=root->left?root->val-root->left->val:root->right->val-root->val;
        vector<int> vc;
        
        minDiff(root, df, vc);      
        
        return df;
    }
    
    void minDiff(TreeNode * root, int& df, vector<int>& vc){
        if(root->left)  minDiff(root->left, df, vc);
        if(!vc.empty()){
            df=root->val-vc.back()<df?root->val-vc.back():df;
            vc.pop_back();
        }
        vc.push_back(root->val);
        if(root->right) minDiff(root->right, df, vc);
        
        return ;
    }
    
};
