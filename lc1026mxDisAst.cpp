/*
1026. Maximum Difference Between Node and Ancestor

Companies	Amazon
Related Topics	Tree, Depth-first Search 

Runtime: 12 ms
Memory Usage: 13.6 MB
Your runtime beats 44.43 % of cpp submissions.
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
    int maxAncestorDiff(TreeNode* root) {
        // post-order DFS, O(n) time 
        int ds=0;
        dfs( root, ds);
        return ds;
    }
    
protected:
    pair<int,int> dfs( TreeNode * tn, int& ds){// post-order DFS; min, max of subtree rooted at tn
        int mn=tn->val, mx=tn->val;
        pair<int,int> pt;
        
        if(tn->left){
            pt=dfs( tn->left, ds);
            if(pt.first<mn) mn=pt.first;
            if(mx<pt.second)mx=pt.second;
        }
        
        if(tn->right){
            pt=dfs( tn->right, ds);
            if(pt.first<mn) mn=pt.first;
            if(mx<pt.second)mx=pt.second;
        }
        
        if(ds<tn->val-mn)   ds=tn->val-mn;
        if(ds<mx-tn->val)   ds=mx-tn->val;
        
        return make_pair( mn, mx);
    }
};