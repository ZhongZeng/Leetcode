
/*
Leetcode 701. Insert into a Binary Search Tree

Related Topics 
Tree 
Similar Questions 
Search in a Binary Search Tree

Next challenges: Find Duplicate Subtrees, 
Serialize and Deserialize N-ary Tree, N-ary Tree Postorder Traversal

Test Case:
[4,2,7,1,3]
5

Runtime: 52 ms
Your runtime beats 95.43 % of cpp submissions.

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // val guranteed not in existing tree 
        dfs( root, val );
        
        return root; 
    }
    
    void dfs( TreeNode * tr, int & val){// pre-order DFS 
        
        if(val<tr->val){
            if(tr->left){
                dfs( tr->left, val);
            }else{
                TreeNode * ts= new TreeNode(val);
                tr->left=ts;
            }
        }else{// tr->val<val
            if(tr->right){
                dfs( tr->right, val);
            }else{
                TreeNode * ts= new TreeNode(val);
                tr->right=ts;
            }            
        }
        
        return ;
    }
};
