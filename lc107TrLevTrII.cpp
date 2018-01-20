

/*
Leetcode 107. Binary Tree Level Order Traversal II

Related Topics 
Tree, Breadth-first Search
Similar Questions 
Binary Tree Level Order Traversal, Average of Levels in Binary Tree

Next challenges: Balanced Binary Tree, Course Schedule, 
Verify Preorder Sequence in Binary Search Tree

Test Cases:
[]
[3,9,20,null,null,15,7]

Runtime: 6 ms
Your runtime beats 10.22 % of cpp submissions.

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		// BFS 
        vector<int> vc;
        vector<vector<int>> rt;
        vector<TreeNode*> vt1, vt2;
        vector<vector<TreeNode*>> vr;
        if(!root)   return rt;
        vt1.push_back(root);
        
        while(!vt1.empty()){
            vr.push_back(vt1);
            vt2.clear();
            for(int i=0; i<vt1.size(); i++){
                if(vt1[i]->left)    vt2.push_back(vt1[i]->left);
                if(vt1[i]->right)   vt2.push_back(vt1[i]->right);
            }
            
            if(vt2.empty()) break;
            vr.push_back(vt2);
            vt1.clear();
            for(int i=0; i<vt2.size(); i++){
                if(vt2[i]->left)    vt1.push_back(vt2[i]->left);
                if(vt2[i]->right)   vt1.push_back(vt2[i]->right);
            }
        }
        
        for(int i=vr.size()-1; -1<i; i--){
            vc.clear();
            for(int j=0; j<vr[i].size(); j++){
                vc.push_back(vr[i][j]->val);
            }
            rt.push_back(vc);
        }
        
        return rt;
    }
};
