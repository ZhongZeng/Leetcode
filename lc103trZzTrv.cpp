
/*
Leetcode 103. Binary Tree Zigzag Level Order Traversal

Related Topics 
Stack, Tree, Breadth-first Search
Similar Questions 
Binary Tree Level Order Traversal

Next challenges: Construct Binary Tree from Inorder and Postorder Traversal, 
Course Schedule II, Convert BST to Greater Tree

Test CAses:
[3,9,20,null,null,15,7]
[3,9,20,null,null,15,7,6,null,20,null,21]

Runtime: 5 ms
Your runtime beats 18.30 % of cpp submissions. 

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // BFS
        vector<int> vc;
        vector<vector<int>> rt;
        vector<TreeNode*> tr1, tr2;
        if(!root)   return rt;
        tr1.push_back(root);
        
        while(!tr1.empty()){
            vc.clear();
            tr2.clear();
            for(int i=tr1.size()-1; -1<i; i--){
                vc.push_back(tr1[i]->val);
                if(tr1[i]->left)    tr2.push_back(tr1[i]->left);
                if(tr1[i]->right)   tr2.push_back(tr1[i]->right);
            }
            rt.push_back(vc);
            
            if(tr2.empty()) return rt;
            vc.clear();
            tr1.clear();            
            for(int i=tr2.size()-1; -1<i; i--){
                vc.push_back(tr2[i]->val);
                if(tr2[i]->right)   tr1.push_back(tr2[i]->right);
                if(tr2[i]->left)    tr1.push_back(tr2[i]->left);
            }      
            rt.push_back(vc);
        }
            
        return rt;
    }
};
