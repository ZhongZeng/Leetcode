/*
1080. Insufficient Nodes in Root to Leaf Paths

Companies	Amazon
Related Topics	Depth-first Search 

Test Cases:
[1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]
1

Runtime: 68 ms, faster than 25.09% of C++ online submissions for Insufficient Nodes in Root to Leaf Paths.
Memory Usage: 26.3 MB, less than 100.00% of C++ online submissions for Insufficient Nodes in Root to Leaf Paths.
Next challenges: Shopping Offers, Redundant Connection II, Maximum Product of Splitted Binary Tree
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // post-order DFS, O(n) time&space
        return sufficientSubset( root, limit, 0);
    }
    
protected:
    TreeNode* sufficientSubset(TreeNode* root, int & limit, int sum){
        sum+=root->val;
        if(root->left==NULL&&root->right==NULL)
            return sum<limit?NULL:root;
        
        if(root->left)
            root->left=sufficientSubset( root->left, limit, sum);
        if(root->right)
            root->right=sufficientSubset( root->right, limit, sum);
        return (root->left==NULL&&root->right==NULL)?NULL:root;
    }
};