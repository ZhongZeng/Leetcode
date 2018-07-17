
/*
Leetcode 700. Search in a Binary Search Tree

Related Topics 
Tree 
Similar Questions 
Closest Binary Search Tree Value, Insert into a Binary Search Tree

Test Cases:
[4,2,7,1,3]
5
[4,2,7,1,3]
2

Next challenges: Insert into a Binary Search Tree

Runtime: 24 ms
Your runtime beats 98.57 % of cpp submissions.

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
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<TreeNode *> rt;
        dfs( root, val, rt);
        return rt.empty()?NULL:rt[0];
    }
    
    void dfs(TreeNode * tr, int& val, vector<TreeNode *>& rt){
        //cout<<tr->val<<" ";
        if(0<rt.size())  return ;
        if(!tr) return ;

        if(tr->val<val){
            dfs( tr->right, val, rt);
        }else if(val<tr->val){
            dfs( tr->left, val, rt);
        }else{
            rt.push_back(tr);
            return ;            
        }
        
        return ;
    }
};
