
/*652. Find Duplicate Subtrees

Related Topics: Tree 
Similiar Questions: Serialize and Deserialize Binary Tree, Serialize and Deserialize BST, 
Construct String from Binary Tree

Runtime: 32 ms, faster than 36.07% of C++ online submissions for Find Duplicate Subtrees.

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // post-order DFS, to make sure all nodes in subtree have been visited 
		unordered_map<string,list<TreeNode*>> um; 
		vector<TreeNode*> vt;
		
		dfs( root, um );
		
		for( unordered_map<string,list<TreeNode*>>::iterator umi=um.begin(); umi!=um.end(); umi++)
			if(1<umi->second.size())	vt.push_back(umi->second.front());
		
		return vt;
    }
	
	string dfs( TreeNode * tr, unordered_map<string,list<TreeNode*>>& um){
        if(!tr) return "";
        
		string l=dfs(tr->left, um), r=dfs(tr->right, um);
		l=l+"l"+r+"r"+to_string(tr->val);
		
		unordered_map<string,list<TreeNode*>>::iterator umi=um.find(l);
		if(umi!=um.end()){
            umi->second.push_back(tr);
        }else{
            list<TreeNode*> ls={tr};
            um.emplace(l,ls);
        }
		
		return l;
	}
};
