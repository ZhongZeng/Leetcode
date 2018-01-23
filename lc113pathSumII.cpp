

/*
Leetcode 113. Path Sum II

Related Topics 
Tree, Depth-first Search
Similar Questions 
Path Sum, Binary Tree Paths, Path Sum III, Path Sum IV

Test Cases:
[5,4,8,11,null,13,4,7,2,null,null,5,1]
22
[]
0

Runtime: 18 ms
Your runtime beats 10.45 % of cpp submissions.

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // tree, DFS, recursion
        vector<vector<int>> rt;
        vector<int> vc;
        if(!root)   return rt;
        
        pathSum(root, 0, sum, rt, vc);
        
        return rt;
    }
    
    void pathSum(TreeNode* root, int t, int sum, vector<vector<int>>& rt, vector<int> vc){
        vc.push_back(root->val);
        t+=root->val;
        if(root->right){
            pathSum(root->right, t, sum, rt, vc);
            if(root->left)  pathSum(root->left, t, sum, rt, vc);
        }else{
            if(root->left){
                pathSum(root->left, t, sum, rt, vc);
            }else{
                if(t==sum)  rt.push_back(vc);
            }
        }
        
        return ;
    }
    
};
