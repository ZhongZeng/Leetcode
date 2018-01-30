

/*
Leetcode 199. Binary Tree Right Side View

Related Topics 
Tree, Depth-first Search, Breadth-first Search 
Similar Questions 
Populating Next Right Pointers in Each Node, Boundary of Binary Tree

Next challenges: Populating Next Right Pointers in Each Node, Boundary of Binary Tree

Test Cases:
[]
[1,2,3,null,4,5]

Runtime: 4 ms
Your runtime beats 11.39 % of cpp submissions.

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
    vector<int> rightSideView(TreeNode* root) {
        // O(n) time
        vector<int> rt;
        if(!root)   return rt;
        vector<TreeNode*> vc={root}, vd;
        TreeNode * tr;
        
        while(!vc.empty()){
            vd.clear();
            for(int i=0; i<vc.size(); i++){
                if(vc[i]->left) vd.push_back(vc[i]->left);
                if(vc[i]->right)vd.push_back(vc[i]->right);
            }
            rt.push_back(vc.back()->val);
            
            if(vd.empty())  return rt;
            vc.clear();
            for(int i=0; i<vd.size(); i++){
                if(vd[i]->left) vc.push_back(vd[i]->left);
                if(vd[i]->right)vc.push_back(vd[i]->right);
            }
            rt.push_back(vd.back()->val);
        }
        
        return rt;
    }
};
