/*
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

Medium
Companeis	Facebook
Related Topics	Tree

Test Cases:
[7,4,3,null,null,6,19]
3

Runtime: 704 ms, faster than 86.16% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
Memory Usage: 164.5 MB, less than 100.00% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
Next challenges: Smallest String Starting From Leaf, Tree Diameter, Smallest Common Region
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // Tree, DFS; O(n) time, O(h) space
        TreeNode * tr1=original, * tr2=cloned;
        return dfs( tr1, tr2, target);
    }
protected:
    TreeNode * dfs(TreeNode* tr1, TreeNode* tr2, TreeNode* target){
        if(tr1==NULL)   return NULL;
        if(tr1==target) return tr2;
        TreeNode * left=dfs( tr1->left, tr2->left, target), * right=dfs(tr1->right, tr2->right, target);
        if(left!=NULL)  return left;
        if(right!=NULL) return right;
        return NULL;
    }
};