
/*
Leetcode 572. Subtree of Another Tree

Companies 
Facebook, eBay
Related Topics 
Tree 
Similar Questions 
Count Univalue Subtrees, Most Frequent Subtree Sum

Test Cases:
[3,4,5,1,2]
[4,1,2]

Runtime: 16 ms
Your runtime beats 99.31 % of cpp submissions.

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
		// O(n) time 
		if(!t)	return false;
        int d=0;
		bool b=false;
        vector<TreeNode*> vt={t}, ut;
        
        while( !vt.empty() ){// count t's height
            ut.clear();
			for( int i=0; i<vt.size(); i++){
				if(vt[i]->left)	ut.push_back(vt[i]->left);
				if(vt[i]->right)	ut.push_back(vt[i]->right);
			}
			vt=ut;
			d++;
        }
		
		dfs( s, t, d, b);
        
        return b;
    }
	
	int dfs( TreeNode* tr, TreeNode * t, int& d, bool& b ){// post-order DFS to calculate height 
		if(!tr)	return 0;
        if(b)   return -d;// if b==true, stop dfs
		int lf=dfs(tr->left, t, d, b), rg=dfs(tr->right, t, d, b), h=lf<rg?rg:lf;

		if(h==d-1&&sameTree(tr,t))	b=true;
		
		return h+1;
	}
	
	bool sameTree( TreeNode* tr, TreeNode* ts){
		vector<TreeNode*> vr={tr}, vs={ts}, ur, us;
		
		while(!vr.empty()){
			ur.clear();
			us.clear();
			for( int i=0; i<vr.size(); i++){
				if(vr[i]->val!=vs[i]->val){
					return false;
				}else{
					if(vr[i]->left){
						if(!vs[i]->left)	return false;
						ur.push_back(vr[i]->left);
						us.push_back(vs[i]->left);
					}
					if(vr[i]->right){
						if(!vs[i]->right)	return false;
						ur.push_back(vr[i]->right);
						us.push_back(vs[i]->right);
					}				
				}
			}
            vr=ur;
            vs=us;
		}
		
		return true;
	}
};
