
/*
Leetcode 270. Closest Binary Search Tree Value

Companies 
Google, Microsoft, Snapchat
Related Topics 
Binary Search, Tree
Similar Questions 
Count Complete Tree Nodes, Closest Binary Search Tree Value II

Next challenges: Count Complete Tree Nodes, Closest Binary Search Tree Value II

Test Cases:
[1]
4.428571
[5,3,8,1,4,7,11]
7.1
[1500000000,1400000000]
-1500000000.0

Runtime: 11 ms
Your runtime beats 11.30 % of cpp submissions.

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
    int closestValue(TreeNode* root, double target) {
        // DFS, pre-order traversal; BST 
        int t=root->val;
        double df=abs(root->val/3.0-target/3.0);
        
        while(root){
            if(abs(root->val/3.0-target/3.0)<df){
                t=root->val;
                df=abs(root->val/3.0-target/3.0);
            }
            root=target<root->val?root->left:root->right;
        }
        
        return t;
    }
    
    double abs(double i){
        return i<0?0-i:i;
    }
};