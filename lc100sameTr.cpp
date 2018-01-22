

/*
Leetcode 100. Same Tree

Related Topics 
Tree, Depth-first Search

Next challenges: Binary Tree Postorder Traversal, Delete Node in a BST, 
Find Largest Value in Each Tree Row

Test Cases:
[]
[]
[1]
[]
[1,2,3]
[1,2,3]
[1,2]
[1,null,2]
[1,2,1]
[1,1,2]

Runtime: 3 ms
Your runtime beats 1.35 % of cpp submissions. (which is within majority)

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL){
            if(q!=NULL) return false;
            else    return true;
        }else{
            if(q==NULL) return false;
        }
        TreeNode* tp, *tq;
        stack<TreeNode*> sp, sq;
        sp.push(p);
        sq.push(q);
        
        while(!(sp.empty()||sq.empty())){
            tp=sp.top();
            tq=sq.top();    
            sp.pop();
            sq.pop();             
            
            if(tp->val!=tq->val)    return false;
            
            if(tp->left!=NULL){
                if(tq->left!=NULL){
                    sp.push(tp->left);
                    sq.push(tq->left);                    
                }else{
                    return false;
                }
            }else{
                if(tq->left!=NULL)  return false;
            }
                
            if(tp->right!=NULL){
                if(tq->right!=NULL){
                    sp.push(tp->right);
                    sq.push(tq->right);                    
                }else{
                    return false;
                }
            }else{
                if(tq->right!=NULL)  return false;
            }
        }
        
        return sp.empty()&&sq.empty();
    }
};