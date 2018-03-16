
/*
Leetcode 366. Find Leaves of Binary Tree

Companies 
LinkedIn
Related Topics 
Tree, Depth-first Search

Next challenges: Convert Sorted List to Binary Search Tree, 
Nested List Weight Sum II, Matchsticks to Square

Test Case:
[1]
[1,2,3,4,5]

Runtime: 3 ms
Your runtime beats 94.18 % of cpp submissions. (EXCLLENT!!)

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> rt;
        if(!root)   return rt;
        
        int r=dfs(root, rt);
        
        return rt;
    }
    
    int dfs(TreeNode * tr, vector<vector<int>>& rt){
        // dfs, post-order traversal
        if(!tr) return 0;
        int l=dfs(tr->left, rt), r=dfs(tr->right, rt);
        
        if(l<r){
            if(rt.size()<r+1){
                vector<int> vc;
                vc.push_back(tr->val);
                rt.push_back(vc);
            }else{// depth can increase only by 1
                rt[r].push_back(tr->val);
            }
            return r+1;
        }else{
            if(rt.size()<l+1){
                vector<int> vc;
                vc.push_back(tr->val);
                rt.push_back(vc);
            }else{
                rt[l].push_back(tr->val);
            }
            return l+1;
        }
    }
};
