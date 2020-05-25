/*
1448. Count Good Nodes in Binary Tree

Companies	Microsoft
Related Topics	Tree, Depth-first Search

Test Cases:
[3,1,4,3,null,1,5]
[3,3,null,4,2]
[1]

Runtime: 204 ms, faster than 82.86% of C++ online submissions for Count Good Nodes in Binary Tree.
Memory Usage: 86.5 MB, less than 100.00% of C++ online submissions for Count Good Nodes in Binary Tree.
Next challenges: Construct Binary Tree from Inorder and Postorder Traversal, 
Redundant Connection II, Lexicographically Smallest Equivalent String
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
    int goodNodes(TreeNode* root) {
        // pre-order DFS; O(n) time, O(h) space; easy
		if(!root)	return 0;
		return dfs( root, root->val);
    }
	
protected:
	int dfs( TreeNode * tr, int mx){
		if(!tr)	return 0;
		if(mx<=tr->val)	mx=tr->val;
		return (mx<=tr->val?1:0)+dfs( tr->left, mx)+dfs( tr->right, mx);
	}
};