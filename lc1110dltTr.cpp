/*
1110. Delete Nodes And Return Forest

Tag: Binary Tree, DFS (suggested) 

Test Case:
"1.1.1.1"

Test Cases:
[1,2,3,4,5,6,7]
[3,5]
[1,2,3,null,null,null,4]
[2,1]

Runtime: 20 ms
Memory Usage: 19.1 MB
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // post-order DFS; O(n) time 
        vector<TreeNode*> rt;
        unordered_set<int> us;
        for( int i=0; i<to_delete.size(); i++)  us.emplace(to_delete[i]);// assuming no duplicate in to_delete
        
        if(!root)   return rt;
        dfs( root, us, rt);
        if(us.find(root->val)==us.end())    rt.push_back(root);// post-order
        
        return rt;
    }
    
protected:
    bool dfs(TreeNode * tr, unordered_set<int>& us, vector<TreeNode*>& rt){// true: deleted; false: not deleted
        if(!tr) return true;
        
        if(dfs( tr->left, us, rt))  tr->left=NULL;// DFS
        if(dfs( tr->right, us, rt)) tr->right=NULL;// DFS
        
        if(us.find(tr->val)!=us.end()){// post-order
            if(tr->left)    rt.push_back(tr->left);
            if(tr->right)   rt.push_back(tr->right);
            return true;
        }
        
        return false;
    }
};