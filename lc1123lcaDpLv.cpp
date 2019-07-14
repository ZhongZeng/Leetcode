/*
1123. Lowest Common Ancestor of Deepest Leaves

Companies	Facebook 
Related Topics	Tree, Depth-first Search 

Test Cases:
[1,2,3]
[1,2,3,4,5]

Runtime: 16 ms
Memory Usage: 19.6 MB
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // DFS, O(n) time
        int dp=calDepth(root), ct=countDpLv( root, dp, 1);// count deepest leaves, no need to find all
        TreeNode * lca=NULL;
        findLCA( root, lca, ct, dp, 1);
        return lca;
    }
    
protected:
    int calDepth(TreeNode * tr){// post-order DFS, O(n) time; calculate deepest depth, root is 1  
        if(!tr) return 0;
        int lf=calDepth(tr->left), rg=calDepth(tr->right);
        return lf>rg?lf+1:rg+1;
    }
    
    int countDpLv( TreeNode * tr, int& dp, int td){// post-order DFS, O(n) time; count no. of deepest leaves 
        if(!tr) return 0;
        int lf=countDpLv( tr->left, dp, td+1), rg=countDpLv( tr->right, dp, td+1);
        return lf+rg+(td==dp?1:0);
    }
    
    int findLCA( TreeNode * tr, TreeNode*& lca, int& ct, int& dp, int td){// post-order DFS; O(n) time; lca: reference to a pointer 
        if(!tr) return 0;
        int lf=findLCA( tr->left, lca, ct, dp, td+1), rg=findLCA( tr->right, lca, ct, dp, td+1),
            tc=lf+rg+(td==dp?1:0);
        if(tc==ct&&lca==NULL)  lca=tr;
        return tc;//  no. of deepest leaves in subtree 
    }
};