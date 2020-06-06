/*
1469. Find All the Lonely Nodes

Easy
Companies	Microsoft
Related Topics	Tree, Depth-first Search

Test Cases:
[1,2,3,null,4]
[7,1,4,6,null,5,3,null,null,null,null,null,2]

Runtime: 12 ms, faster than 99.32% of C++ online submissions for Find All the Lonely Nodes.
Memory Usage: 20.2 MB, less than 100.00% of C++ online submissions for Find All the Lonely Nodes.
Next challenges: Inorder Successor in BST II, Boundary of Binary Tree,
Path With Maximum Minimum Value
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> nd;
        dfs( root, nd);
        return nd;
    }
    
protected:
    void dfs( TreeNode * tr, vector<int> & nd){
        if(tr->left){
            dfs( tr->left, nd);
            if(tr->right)   dfs( tr->right, nd);
            else    nd.push_back(tr->left->val);
        }else{
            if(tr->right){
                nd.push_back(tr->right->val);
                dfs( tr->right, nd);
            }
        }
        return ;
    }
};