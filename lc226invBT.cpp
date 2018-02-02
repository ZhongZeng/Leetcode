/*

Leetcode 226. Invert Binary Tree

Related Topics 
Tree

Next challenges: Construct Binary Tree from Inorder and Postorder Traversal, 
Find Leaves of Binary Tree, Binary Tree Longest Consecutive Sequence II

Test Cases:
[]
[1,2,3,4,5]
[1,2,3,null,4,5,null,6]

Runtime: 4 ms
Your runtime beats 0.52 % of cpp submissions. which is within majority 

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
    TreeNode* invertTree(TreeNode* root) {
        // O(n) time, O(n) space
        if(!root)   return root;
        TreeNode* tr=root, * tp;
        vector<TreeNode*> vc={root}, vd;
        
        while(!vc.empty()){
            vd.clear();
            for(int i=0; i<vc.size(); i++){
                if(vc[i]->left) vd.push_back(vc[i]->left);
                if(vc[i]->right)vd.push_back(vc[i]->right);
                tp=vc[i]->right;
                vc[i]->right=vc[i]->left;
                vc[i]->left=tp;           
            }
            
            if(vd.empty())  return root;
            vc.clear();
            for(int i=0; i<vd.size(); i++){
                if(vd[i]->left) vc.push_back(vd[i]->left);
                if(vd[i]->right)vc.push_back(vd[i]->right);
                tp=vd[i]->right;
                vd[i]->right=vd[i]->left;
                vd[i]->left=tp;           
            }            
        }
        
        return root;
    }
};