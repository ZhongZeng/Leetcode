/*
1022. Sum of Root To Leaf Binary Numbers

Companies	Amazon
Related Topics	Tree

Test Case:
[1,0,1,0,1,0,1]

Runtime: 16 ms
Memory Usage: 19.7 MB
Your runtime beats 63.07 % of cpp submissions.

Runtime: 12 ms
Memory Usage: 17 MB
Your runtime beats 98.87 % of cpp submissions.

Next challenges: Closest Binary Search Tree Value II, 
Serialize and Deserialize BST, Redundant Connection II

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
    int sumRootToLeaf(TreeNode* root) {
        // dfs, math; 1000000007
        if(!root)   return 0;
        int rt=0;
        dfs( root, 0, rt);
        return rt;
    }
    
protected:
    void dfs( TreeNode * tr, int num, int& rt){
        num=(num<<1)+tr->val;
        if(1000000007<=num) num-=1000000007;
        
        if(tr->left){
            dfs( tr->left, num, rt);
            if(tr->right)   dfs( tr->right, num, rt);
        }else{
            if(tr->right){
                dfs( tr->right, num, rt);
            }else{
                rt+=num;
                if(1000000007<=rt) rt-=1000000007;
            }
        }
        return ;
    }
};