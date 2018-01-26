
/*
Leetcode 112. Path Sum

Related Topics 
Tree, Depth-first Search
Similar Questions 
Path Sum II, Binary Tree Maximum Path Sum, 
Sum Root to Leaf Numbers, Path Sum III, Path Sum IV

Next challenges: Binary Tree Maximum Path Sum, Path Sum III, Path Sum IV

Test Cases:
[]
1
[]
0
[5,4,8,11,null,13,4,7,2,null,null,null,1]
22
[1,2]
1

Runtime: 9 ms
Your runtime beats 15.03 % of cpp submissions.

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        sum-=root->val;
        if(root->right){
            if(root->left){
                return hasPathSum(root->right,sum)||hasPathSum(root->left,sum);
            }else{
                return hasPathSum(root->right,sum);
            }
        }else{
            if(root->left){
                return hasPathSum(root->left,sum);
            }else{
                return sum==0;
            }
        }
    }
};

/*

// Runtime: 16 ms
// Your runtime beats 1.03 % of cpp submissions.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        else    return hasPathSum0(root, sum);
    }
    
    bool hasPathSum0(TreeNode* root, int sum) {
        if(!root)   return false;
        sum-=root->val;
        if(root->right){
            if(root->left){
                return hasPathSum0(root->right,sum)||hasPathSum0(root->left,sum);
            }else{
                return hasPathSum0(root->right,sum);
            }
        }else{
            if(root->left){
                return hasPathSum0(root->left,sum);
            }else{
                return sum==0;
            }
        }
    }
};
*/


/*
// Wrong Answer
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // thought it would be complex, but Easy tells me it's easy
        // recursion
        // [] 0 is false, bitchy
        if(!root)   return false;
        return hasPathSum0(root, sum);
    }

    bool hasPathSum0(TreeNode* root, int sum) {
        if(!root)   return sum==0;
        sum-=root->val;
        return hasPathSum0(root->right, sum)||hasPathSum0(root->left, sum);
    }    
    
};
*/
