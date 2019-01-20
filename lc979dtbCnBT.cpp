/*
979. Distribute Coins in Binary Tree

Related Topics: Tree, Depth-first Search 

Test Cases:
[3,0,0]
[0,3,0]
[1,0,2]
[1,0,0,null,3]

Runtime: 8 ms
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
    int distributeCoins(TreeNode* root) {
        // post-order DFS, b/c need to know how many to distribute to each child
        // We calculate the difference between the total number of nodes( the total number of conis there should be) and the total number of coins there actually are in the subtree rooted at TreeNode nd. Denote this difference as t. The dfs() function returns t. Then, we need to move abs(t) coins between nd's parent and nd. If t is positive, it means we need to move coins from nd's parent to nd. If t is negative, it means we need to move coins fron nd to nd's parent. If t is 0, it means we don't need to move any coins between nd and nd's parent. 
        int sum=0;
        dfs( root, sum);
        return sum;
    }
    
    int dfs( TreeNode * nd, int & sum){
        // count # coins move from nd to its children 
        if(!nd) return 0;
        int lf=dfs(nd->left,sum), rg=dfs(nd->right,sum);
        sum+=abs(lf)+abs(rg);
        return lf+rg+1-nd->val;// return # coins reqeuired(# nodes) - # existing coins 
    }
};