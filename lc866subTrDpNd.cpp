
/*
Leetcode 866. Smallest Subtree with all the Deepest Nodes

Test Cases: 
[3,5,1,6,2,0,8,null,null,7,4]
[3,5,1,6,2,0,8,null,null,7,4,6]
[0,1,3,null,2]

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // lowest common ancester; O(n) 2 paths
        TreeNode * rt;
        vector<TreeNode *> vc, vd, vt;
        vc.push_back(root);
        int dp=0, num=0;// deepest depth, # nodes w/ deepest depth 
        
        while(!vc.empty()){// BFS 
            vd.clear();
            for( int i=0; i<vc.size(); i++){
                if(vc[i]->left) vd.push_back(vc[i]->left);
                if(vc[i]->right)    vd.push_back(vc[i]->right);
            }
            num=vc.size();
            dp++;
            vc=vd;
        }
        
        dfs( root, vt, dp, num, 1);
        
        return vt[0];
    }
    
    int dfs(TreeNode * tr, vector<TreeNode *>& vt, int& dp, int& num, int d){// post-order DFS to find LCA 
        if(!tr) return 0;
        int n=dp!=d?0:1;// 1-deepest element 
        //cout<<tr->val<<":"<<d<<" ";
        
        n+=dfs( tr->left, vt, dp, num, d+1);
        n+=dfs( tr->right, vt, dp, num, d+1);
        
        if(n==num&&vt.empty())  vt.push_back(tr);
        
        return n;
    }
};