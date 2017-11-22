

/*
Leetcode 104. Maximum Depth of Binary Tree

Related Topics 
Tree, Depth-first Search 
Similar Questions 
Balanced Binary Tree, Minimum Depth of Binary Tree 

Next challenges: Balanced Binary Tree

Runtime: 6 ms
You are here! 
Your runtime beats 18.60 % of cpp submissions.

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
    int maxDepth(TreeNode* root) {
        if(!root)   return 0;
        int dep=0;
        queue<TreeNode*> qt;        
        queue<int> qi;        
        TreeNode *tn=root;
        qt.push(tn);
        qi.push(1);        
        while( !qt.empty() ){
            if(qt.front()->left!=NULL){
                qt.push(qt.front()->left);
                qi.push(qi.front()+1);
                if(qt.front()->right!=NULL){
                    qt.push(qt.front()->right);
                    qi.push(qi.front()+1);
                }                
            }else{
                if(qt.front()->right!=NULL){
                    qt.push(qt.front()->right);
                    qi.push(qi.front()+1);                    
                }else{
                    dep=dep<qi.front()? qi.front():dep;
                }                
                
            }            
            qt.pop();
            qi.pop();
        }
        
        return dep;
    }
};
