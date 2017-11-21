
/*

Leetcode 404. Sum of Left Leaves

Related Topics 
Tree 

Next challenges: Maximum Depth of Binary Tree,
Path Sum III, Second Minimum Node In a Binary Tree

Test Cases:
[null]
[3,9,20,null,null,15,7]

Runtime: 3 ms
You are here! 
Your runtime beats 44.63 % of cpp submissions.

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)  return 0;
        TreeNode * tn=root;
        queue<TreeNode *> qt;
        queue<int> qi;
        qt.push(tn);
        qi.push(0);
        int sum=0;
        while(!qt.empty()){
            tn=qt.front();
            if( tn->left!=NULL ){
                qt.push(tn->left);
                qi.push(1);
                if(tn->right!=NULL){
                    qt.push(tn->right);
                    qi.push(0);
                } 
            }else{
                if(tn->right!=NULL){
                    qt.push(tn->right);
                    qi.push(0);
                }else{                    
                    if(qi.front()!=0){
                        sum+=tn->val;
                    }                                        
                }    
            }
            qt.pop();
            qi.pop();
        }
        return sum;
    }
};
