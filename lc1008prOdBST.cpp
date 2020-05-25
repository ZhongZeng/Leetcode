/*
1008. Construct Binary Search Tree from Preorder Traversal

Related Topics:	Tree 

Test Case:
[8,5,1,7,10,12]

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // BST, DFS, tree; preorder.size() in [1,100]; distinct values in BST 
        TreeNode * rt=new TreeNode(preorder[0]), * tp;
        vector<TreeNode*> ac={rt};// path of larger ancestors 
        
        for( int i=1; i<preorder.size(); i++){
            TreeNode * nt=new TreeNode(preorder[i]);
            //cout<<nt->val<<": ";
            
            if(nt->val < ac.back()->val){
                ac.back()->left=nt;
                ac.push_back(nt);
            }else{
                while( 0<ac.size() && ac.back()->val < nt->val){
                    tp=ac.back();
                    ac.pop_back();
                    //cout<<tp->val<<", ";
                }
                tp->right=nt;
                ac.push_back(nt);// no need to push_back tp b/t nt, b/c tp has nt as right child
            }
            //cout<<endl;
        }
        
        return rt;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
Memory Usage: 10 MB, less than 95.24% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
Next challenges: Closest Binary Search Tree Value II, Longest ZigZag Path in a Binary Tree, 
Count Good Nodes in Binary Tree
*/
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // pre-order DFS, BST; O(3*n) time
		if(preorder.size()<1)	return NULL;
		TreeNode * root=new TreeNode(preorder[0]);
		vector<TreeNode*> nodes={root};// nodes w/t right child && in same path to root
		dfs( preorder, 1, nodes);
		return root;
    }
	
protected:
	void dfs( vector<int> & preorder, int pos, vector<TreeNode*> nodes ){
		if(!(pos<preorder.size()))	return ;
		
		TreeNode * tr=new TreeNode(preorder[pos]);
		if(preorder[pos]<nodes.back()->val){
			nodes.back()->left=tr;
		}else{
			// find tr b/t nodes[-1] and nodes[-2]
			while(1<nodes.size()&&nodes[nodes.size()-2]->val<preorder[pos])	nodes.pop_back();
			nodes.back()->right=tr;
			nodes.pop_back();// only save node w/t left child
		}
		nodes.push_back(tr);
		
		dfs( preorder, pos+1, nodes);
		
		return ;
	}
};