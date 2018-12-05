

/*
Leetcode 543. Diameter of Binary Tree

Related Topics 
Tree

Next challenges: Closest Binary Search Tree Value II, 
Serialize and Deserialize Binary Tree, Boundary of Binary Tree

Test Cases:
[1,2,3,4,5]
[1,null,2,3,4,5]
[1,2,3]
[1]
[1,2,3,null,3,null,4,5]
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
 
// Runtime: 4 ms 
// Your runtime beats 100.00 % of cpp submissions.
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
		// DFS, all pathes go through a node as the parent 
        int mx=1;
		
		dfs( root, mx); 
		
		return mx-1;
    }
	
protected:	
	int dfs( TreeNode* tr, int& mx){// post-order DFS; return longest length from tr to leaf 
		if(!tr)	return 0;
	
		int l=dfs(tr->left,mx), r=dfs(tr->right,mx);
		
		if(mx<l+r+1)	mx=l+r+1;
		
		return l<r?r+1:l+1;
	}
};


// Runtime: 9 ms	Your runtime beats 40.97 % of cpp submissions.
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // sum of max depthes of subtrees, O(n) time
        if(!root)   return 0;
        int mx=1;
        diameterOfBinaryTree(root, mx, 0);
        return mx-2;
    }
    
    int diameterOfBinaryTree(TreeNode* root, int& mx, int d){
        // return larger of depthes of left&right subtrees 
        // d: depth of this root to root
        if(!root)   return d;
        int l=diameterOfBinaryTree(root->left, mx, d+1), r=diameterOfBinaryTree(root->right, mx, d+1);
        mx=mx<l+r-d*2?l+r-d*2:mx;
        //cout<<root->val<<" "<<d<<" "<<l<<" "<<r<<endl;
        return l<r?r:l;
    }
};