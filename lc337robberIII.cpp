
/*
Leetcode 337. House Robber III

Related Topics 
Tree, Depth-first Search 
Similar Questions 
House Robber, House Robber II

Test Cases:
[3,2,3,null,3,null,1]

Runtime: 13 ms
Your runtime beats 41.86 % of cpp submissions.

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
    int rob(TreeNode* root) {
        vector<int> vc=robber(root);
        return vc[0];
    }
    
    vector<int> robber(TreeNode* root){
        // DFS, post-order traversal; DP
		// tried pre-order traversal and failed 
        vector<int> vc={0,0}, vl, vr;
        if(!root)   return vc;
        
        vl=robber(root->left);
        vr=robber(root->right);
        
        vc[1]=vl[0]+vr[0];
        vc[0]=vc[1]<vl[1]+vr[1]+root->val?vl[1]+vr[1]+root->val:vc[1];
        
        return vc;
    }
    
};