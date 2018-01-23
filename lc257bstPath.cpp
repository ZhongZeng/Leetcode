
/*
Leetcode 257. Binary Tree Paths

Related Topics 
Tree, Depth-first Search
Similar Questions 
Path Sum II

Next challenges: Path Sum II

Test Cases:
[1,2,3,null,5]
[1,2,3,4,5,null,null.8]
[1,2]

Runtime: 7 ms
Your runtime beats 14.77 % of cpp submissions.

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
    vector<string> binaryTreePaths(TreeNode* root) {
        // recursion, DFS, tree
        vector<string> vc;
        if(!root)   return vc;
        string s;
        s.append(to_string(root->val));

        if(root->right){
            bstPath(root->right, vc, s);
            if(root->left)  bstPath(root->left, vc, s);
        }else{
            if(root->left)  bstPath(root->left, vc, s);
            else    vc.push_back(s);
        }     
        
        return vc;
    }
    
    void bstPath(TreeNode* root, vector<string>& vc, string s){
        s.append("->");
        s.append(to_string(root->val));
        if(root->right){
            bstPath(root->right, vc, s);
            if(root->left)  bstPath(root->left, vc, s);
        }else{
            if(root->left)  bstPath(root->left, vc, s);
            else    vc.push_back(s);
        }
        return ;
    }
    
};
