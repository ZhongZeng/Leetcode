

/*
Leetcode 515. Find Largest Value in Each Tree Row

Related Topics 
Tree, Depth-first Search, Breadth-first Search

Next challenges: Count Complete Tree Nodes, 
Shortest Distance from All Buildings, Print Binary Tree

Runtime: 16 ms
Your runtime beats 15.04 % of cpp submissions.

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
    vector<int> largestValues(TreeNode* root) {
        // BFS
		// This should be easy. 
        vector<int> rt;
        if(!root)   return rt;
        vector<TreeNode*> vc,vd;
        vc.push_back(root);
        
        while(!vc.empty()){
            rt.push_back(vc[0]->val);
            vd.clear();
            for(int i=0; i<vc.size(); i++){
                if(rt.back()<vc[i]->val)    rt.back()=vc[i]->val;
                if(vc[i]->right)vd.push_back(vc[i]->right);
                if(vc[i]->left) vd.push_back(vc[i]->left);
            }
            
            if(vd.empty())  return rt;
            rt.push_back(vd[0]->val);
            vc.clear();
            for(int i=0; i<vd.size(); i++){
                if(rt.back()<vd[i]->val)    rt.back()=vd[i]->val;
                if(vd[i]->right)vc.push_back(vd[i]->right);
                if(vd[i]->left) vc.push_back(vd[i]->left);
            }            
        }
        
        return rt;
    }
};
