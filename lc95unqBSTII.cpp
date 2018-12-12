
/*
95. Unique Binary Search Trees II

Related Topics: Dynamic Programming, Tree 
Similiar Questions: Unique Binary Search Trees, Different Ways to Add Parentheses

Runtime: 16 ms, faster than 37.71% of C++ online submissions for Unique Binary Search Trees II.

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
    vector<TreeNode*> generateTrees(int n) {
        // DP, BST 
		vector<TreeNode*> vt;
		vector<int> vn;// # of nodes from root to right-most child
		if(n<1)	return vt;
		vt.push_back(new TreeNode(1));
		vn.push_back(1);
		
		for( int i=2; i<=n ;i++){
			int sz=vt.size();
			for( int j=0; j<sz; j++){
				for( int k=0; k<vn[j]; k++){// insert tn(i) as right child of right k's node tt 
					TreeNode * rt=copyTree(vt[j]), * tt=rt, * tn=new TreeNode(i);
					for( int l=0; l<k; l++)	tt=tt->right;
					tn->left=tt->right;
					tt->right=tn;
					
					vt.push_back(rt);
					vn.push_back(k+2);
				}
				
				TreeNode * tn=new TreeNode(i);// insert i as root 
				tn->left=vt[j];
				
				vt[j]=tn;
				vn[j]=1;
			}
		}
		
		return vt;
    }
	
	TreeNode * copyTree(TreeNode * tr){// pre-order DFS 
		if(!tr)	return tr;
		
		TreeNode * tn=new TreeNode(tr->val);
		tn->left=copyTree(tr->left);
		tn->right=copyTree(tr->right);
		
		return tn;
	}
};
