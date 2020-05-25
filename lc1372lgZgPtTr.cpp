/*
1372. Longest ZigZag Path in a Binary Tree

Companies	Sumerge
Related Topcis	Dynamic Programming, Tree

Test Cases:
[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
[1,1,1,null,1,null,null,1,1,null,1]
[1]

Runtime: 256 ms, faster than 53.41% of C++ online submissions for Longest ZigZag Path in a Binary Tree.
Memory Usage: 93.7 MB, less than 100.00% of C++ online submissions for Longest ZigZag Path in a Binary Tree.
Next challenges: Unique Substrings in Wraparound String, Super Washing Machines
Strange Printer
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
    int longestZigZag(TreeNode* root) {
        // pre-order DFS, Dynamic Programming; O(n) time
        int mx=0;// length of path not # of nodes
        dfs( mx, root, 0, 0);
        return mx;
    }
    
protected:
    void dfs(int & mx, TreeNode* tr, int left, int right){
        // max length inlucidng tr end w/ left/right lastly
        if(!tr)   return ;
        if(mx<left) mx=left;
        if(mx<right)mx=right;
        dfs( mx, tr->left, right+1, 0);
        dfs( mx, tr->right, 0, left+1);
        return ;
    }
};