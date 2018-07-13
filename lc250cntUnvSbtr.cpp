
/*
Leetcode 250. Count Univalue Subtrees

Related Topics 
Tree 
Similar Questions 
Subtree of Another Tree, Longest Univalue Path

Test Cases:
[5,1,5,5,5,null,5]
[]

Runtime: 4 ms
Your runtime beats 97.36 % of cpp submissions.

Next challenges: Subtree of Another Tree

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
    int countUnivalSubtrees(TreeNode* root) {
        int sum=0;
        
        if(root)    dfs( root, sum);
        
        return sum;
    }
    
    bool dfs( TreeNode * tr, int& sum){// count root to count tree 
        bool rg, lf;
        
        if(tr->right){
            rg=dfs(tr->right, sum);
            if(tr->left){
                lf=dfs(tr->left, sum);
                if(rg&&lf&&tr->val==tr->right->val&&tr->val==tr->left->val){
                    sum++;
                    return true;
                }else{
                    return false;
                }
            }else{
                if(rg&&tr->val==tr->right->val){
                    sum++;
                    return true;
                }else{
                    return false;
                }                
            }
        }else{
            if(tr->left){
                lf=dfs(tr->left, sum);
                if(lf&&tr->val==tr->left->val){
                    sum++;
                    return true;
                }else{
                    return false;
                }                
            }else{
                sum++;
                return true;// single node 
            }
        }
        
        return true;
    }
};
