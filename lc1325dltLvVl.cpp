/*
1325. Delete Leaves With a Given Value

Companies	Amazon
Related Topics	Tree, Depth-first Search (suggested)

Test Cases:
[1]
1
[1,2,3,2,null,2,4]
2
[1,3,3,3,2]
3

Runtime: 24 ms	Your runtime beats 50.00 % of cpp submissions.
Memory Usage: 21.6 MB
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs( root, target)?root:NULL;
    }
    
protected:
    int dfs( TreeNode* tr, int & target){
        // O(n) time, O(h) space, post-order DFS 
        if(tr==NULL)    return 0;
        int lf=dfs( tr->left, target), rg=dfs(tr->right, target);
        
        if(lf==0){
            tr->left=NULL;
            if(rg==0){
                tr->right=NULL;
                if(tr->val==target){
                    //delete tr;// delete will result in runtime error
                    return 0;
                }
            }
        }
        if(rg==0)   tr->right=NULL;
        
        return 1;// 0: NULL, 1: NONNULL 
    }
};