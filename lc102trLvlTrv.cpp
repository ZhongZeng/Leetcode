
/*

Leetcode 102. Binary Tree Level Order Traversal

Related Topics 
TreeBreadth-first Search
Similar Questions 
Binary Tree Zigzag Level Order Traversal, Binary Tree Level Order Traversal II, 
Minimum Depth of Binary Tree, Binary Tree Vertical Order Traversal, 
Average of Levels in Binary Tree


Next challenges: Binary Tree Zigzag Level Order Traversal, 
Binary Tree Level Order Traversal II, Binary Tree Vertical Order Traversal

Test Cases:
[]
[3,9,20,null,null,15,7]

Runtime: 6 ms
Your runtime beats 7.90 % of cpp submissions.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode* tr;
        vector<TreeNode*> vc, vb;
        vector<int> vi;
        vector<vector<int>> rt;
        if(!root)   return rt;
    
        vc.push_back(root);
        
        while(!vc.empty()){
            vb.clear();
            vi.clear();
            for(vector<TreeNode*>::iterator it=vc.begin(); it!=vc.end(); it++){
                vi.push_back((*it)->val);
                if((*it)->left)    vb.push_back((*it)->left);
                if((*it)->right)   vb.push_back((*it)->right);
            }
            rt.push_back(vi);
            
            if(vb.empty())  return rt;
            vc.clear();
            vi.clear();
            for(vector<TreeNode*>::iterator it=vb.begin(); it!=vb.end(); it++){
                vi.push_back((*it)->val);
                if((*it)->left)    vc.push_back((*it)->left);
                if((*it)->right)   vc.push_back((*it)->right);
            }
            rt.push_back(vi);
        }
        
        return rt;
    }
};
