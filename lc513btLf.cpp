

/*
Leetcode 513. Find Bottom Left Tree Value

Related Topics 
Tree, Depth-first Search, Breadth-first Search 

Next challenges: Binary Tree Preorder Traversal, 
Boundary of Binary Tree, Find Duplicate Subtrees

Test Case:
[2,1,3]

Runtime: 9 ms
Your runtime beats 61.65 % of cpp submissions.
Runtime: 12 ms
Your runtime beats 36.71 % of cpp submissions.

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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* tn=root;
        queue<TreeNode*> qt;        
        qt.push(tn);
        int i;
        while(!qt.empty()){
            tn=qt.front();
            if(tn->right!=NULL){
                qt.push(tn->right);  
                if(tn->left!=NULL) qt.push(tn->left);
            }else{
                if(tn->left!=NULL) qt.push(tn->left);
                else    i=tn->val;
            }            
            qt.pop();
        }
        return i;
    }
};
