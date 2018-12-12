
/*
653. Two Sum IV - Input is a BST

Related Topics: Tree
Similiar Questions: Two Sum, Two Sum II - Input array is sorted, Two Sum III - Data structure design

Test Cases:
[5,3,6,2,4,null,7]
9
[1,0,4,-2,null,3]
7
[1]
1

Runtime: 20 ms, faster than 98.17% of C++ online submissions for Two Sum IV - Input is a BST.

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
    bool findTarget(TreeNode* root, int k) {
        // 2-pointer; in-order DFS; O(n) time&space is trival 
		if(!root)	return false;
		TreeNode * tr;
        vector<TreeNode*> vb, ve;
		
		for( tr=root; tr!=NULL; tr=tr->left)	vb.push_back(tr);// image root as right child of an imaginary TreeNode 
		for( tr=root; tr!=NULL; tr=tr->right)ve.push_back(tr);// image root as left child of an imaginary TreeNode 
		
		while( vb.back()!=ve.back() ){
			if(vb.back()->val+ve.back()->val<k)	findNextLarger(vb);
			else if(vb.back()->val+ve.back()->val>k)	findNextSmaller(ve);
			else	return true;
		}
		
        return false; 
    }
	
	void findNextLarger(vector<TreeNode*>& vb){
		// indictive prove:
		// When a TreeNode tr is pushed into vb, all its left children are pushed into vb. 
		// tr will be visited&&poped only after all its left children are poped. 
		// At that time, tr's right child is pushed into vb. 
		// The right child tree will be procesed only after tr is vistied&popped and will be procssed the same way as tr. 
		TreeNode * tr=vb.back();
		vb.pop_back();
		
		for( tr=tr->right; tr; tr=tr->left)	vb.push_back(tr);
		
		return ;
	}
	
	void findNextSmaller(vector<TreeNode*>& ve){// similiar to findNextLarger() 
		TreeNode * tr=ve.back();
		ve.pop_back();
		
		for( tr=tr->left; tr; tr=tr->right)	ve.push_back(tr);
		
		return ;
	}
};
