
/*
Leetcode 236. Lowest Common Ancestor of a Binary Tree

Test Cases:
[37,-34,-48,null,-100,-100,48,null,null,null,null,-54,null,-71,-22,null,null,null,8]
node with value -100
node with value -100

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return root;
        vector<TreeNode*> vc;
        int t=lca(root, p, q, vc);
        return vc[0];
    }
    
    int lca(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& vc){
        // DFS; 0:no match; 1: p matched; 2: q matched; 3: both matched or no need to search
        // node values may not be unique
		// I use exactly the same code from 235, except comparing TreeNode* not their values
        if(0<vc.size()) return 3;
        
        if(!root)   return 0;
        
        int l=lca(root->left, p, q, vc);
        if(0<vc.size()||l==3)   return 3;
        int r=lca(root->right, p, q, vc);
        if(0<vc.size()||r==3)   return 3;
        
        if(root==p){
            if(l==2||r==2)  vc.push_back(root);
            else    return 1;
        }else if(root==q){
            if(l==1||r==1)  vc.push_back(root);
            else    return 2;
        }else{
            if((l==1&&r==2)||(l==2&&r==1)){ vc.push_back(root); return 3;}
            
            if(l==0)  return r;
            else    return l;
        }
        return 3;
    }
};