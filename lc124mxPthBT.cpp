
/*
Leetcode 124. Binary Tree Maximum Path Sum

This question improved my understanding of pre/in/post-order DFS 

Companies  
Facebook, Amazon, Microsoft, Google, Pocket Gems, Baidu 
Related Topics 
Tree, Depth-first Search 
Similar Questions 
Path Sum, Sum Root to Leaf Numbers, Path Sum IV, Longest Univalue Path

Test Cases:
[1,2,3]
[-10,9,20,null,null,15,7]

Next challenges: Closest Binary Search Tree Value II, Two Sum IV - Input is a BST, 24 Game

Runtime: 12 ms
Your runtime beats 98.73 % of cpp submissions.

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
    int maxPathSum(TreeNode* root) {
        int rt=root->val, r=dfs( root, 0, rt);
        
        return rt;
    }
    
    int dfs( TreeNode* tr, int p, int& rt){// pre&post order DFS 
        // p:largest path from ancestors to tr; return longest path starting at tr 
        int lf=0, rg=0; 
        
        if(0<p+tr->val){
            if(tr->left)    lf=dfs( tr->left, p+tr->val, rt);
            if(tr->right)   rg=dfs( tr->right, p+tr->val, rt);
        }else{
            if(tr->left)    lf=dfs( tr->left, 0, rt);
            if(tr->right)   rg=dfs( tr->right, 0, rt);
        }
        
        // compare lagest path going thru tr w/ rt 
        if(lf<rg){
            if(lf<p)    rt=rt<p+rg+tr->val?p+rg+tr->val:rt;
            else    rt=rt<lf+rg+tr->val?lf+rg+tr->val:rt;
            return 0<rg+tr->val?rg+tr->val:0;
        }else{
            if(rg<p)    rt=rt<p+lf+tr->val?p+lf+tr->val:rt;
            else    rt=rt<lf+rg+tr->val?lf+rg+tr->val:rt;
            return 0<lf+tr->val?lf+tr->val:0;
        }
        
        return 0;// this statement won't be run 
    }
};
