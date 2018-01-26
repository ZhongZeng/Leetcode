


/*
Leetcode 129. Sum Root to Leaf Numbers

Related Topics 
Tree, Depth-first Search 
Similar Questions 
Path Sum, Binary Tree Maximum Path Sum

Next challenges: Path Sum, Binary Tree Maximum Path Sum

Test Cases:
[]
[1,2,3]

Runtime: 4 ms
Your runtime beats 4.09 % of cpp submissions. which is within majority 

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
    int sumNumbers(TreeNode* root) {
        // recursion
        if(!root)   return 0;
        
        int sum=0;
        sumNumbers(root, sum, 0);
        
        return sum;
    }
    
protected:
    void sumNumbers(TreeNode* root, int & sum, int t){
        t=t*10+root->val;
        
        if(root->right){
            sumNumbers(root->right, sum, t);
            if(root->left){   
                sumNumbers(root->left, sum, t);
            }
        }else{
            if(root->left){
                sumNumbers(root->left, sum, t);
            }else{
                sum+=t;
            }            
        }
        
        return ;
    }
    
};
