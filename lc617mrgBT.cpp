
/*

Leetcode 617. Merge Two Binary Trees

Companies 
Amazon
Related Topics 
Tree 

Next challenges: Binary Tree Maximum Path Sum, 
Find Leaves of Binary Tree, Two Sum IV - Input is a BST

Test Cases:
[1,3,2,5]
[2,1,3,null,4,null,7]
[null]
[2,1,3,null,4,null,7]

Runtime: 47 ms
Your runtime beats 31.19 % of cpp submissions.

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // BFS
        if(!t1) return t2;
        if(!t2) return t1;
        TreeNode *rt=t1;
        vector<TreeNode*> v1, v2, v3, v4;
        v1.push_back(t1);
        v2.push_back(t2);
        
        while(!v1.empty()){
            v3.clear();
            v4.clear();
            mergeTrees(v1,v2,v3,v4);
            
            if(v2.empty())  return rt;
            v1.clear();
            v2.clear();
            mergeTrees(v3,v4,v1,v2);
        }
        
        return rt;
    }
    
    void mergeTrees(vector<TreeNode*>& v1, vector<TreeNode*>& v2, vector<TreeNode*>& v3, vector<TreeNode*>& v4){
        for(int i=0; i<v1.size(); i++){
            v1[i]->val+=v2[i]->val;

            if(v1[i]->left){
                if(v2[i]->left){
                    v3.push_back(v1[i]->left);
                    v4.push_back(v2[i]->left);
                }
            }else{
                if(v2[i]->left) v1[i]->left=v2[i]->left;
            }

            if(v1[i]->right){
                if(v2[i]->right){
                    v3.push_back(v1[i]->right);
                    v4.push_back(v2[i]->right);
                }
            }else{
                if(v2[i]->right)    v1[i]->right=v2[i]->right;
            }                
        }        
        
        return ;
    }
};
