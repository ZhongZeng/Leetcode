

/*
Leetcode 114. Flatten Binary Tree to Linked List

Related Topics 
Tree, Depth-first Search

Next challenges: Convert Sorted Array to Binary Search Tree, 
Closest Binary Search Tree Value, Binary Tree Tilt

Test Cases:
[]
[1,2,5,3,4,6]

Runtime: 10 ms
Your runtime beats 18.58 % of cpp submissions.

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
    void flatten(TreeNode* root) {
        // DFS pre-oder traversal
        if(!root)   return;
        TreeNode* tr=root;
        stack<TreeNode*> st;
        if(tr->right)   st.push(tr->right);
        if(tr->left)    st.push(tr->left);
        
        while(!st.empty()){
            //cout<<tr->val<<" ";
            tr->right=st.top();
            tr->left=NULL;
            tr=st.top();
            st.pop();
            if(tr->right)   st.push(tr->right);
            if(tr->left)    st.push(tr->left);
        }
        
        return ;
    }
};