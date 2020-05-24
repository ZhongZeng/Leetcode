/*
1457. Pseudo-Palindromic Paths in a Binary Tree

Companies	Amazon
Related Topics	Bit Manipulation, Tree, Depth-first Search

Test Cases:
[2,3,1,3,1,null,1]
[2,1,1,1,3,null,null,null,null,null,1]
[9]

Runtime: 252 ms	Your runtime beats 50.00 % of cpp submissions.
Memory Usage: 107.4 MB
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        // DFS, O(n) time
        unordered_map<int,int> counts;
        int singulars=0, sum=0;
        dfs( root, counts, singulars, sum);
        return sum;
    }
    
protected:
    void dfs( TreeNode * tr, unordered_map<int,int> & counts, int & singulars, int & sum){
        unordered_map<int,int>::iterator it=counts.find(tr->val);
        if(it!=counts.end())    it->second+=1;
        else    counts.emplace(tr->val, 1);
        singulars+=(counts[tr->val]%2==1)?1:-1;
        
        if(tr->left!=NULL){
            if(tr->right!=NULL) dfs( tr->right, counts, singulars, sum);
            dfs( tr->left, counts, singulars, sum);
        }else{
            if(tr->right!=NULL) dfs( tr->right, counts, singulars, sum);
            else    if(singulars<2) sum++;
        }
        
        counts[tr->val]-=1;
        singulars+=(counts[tr->val]%2==1)?1:-1;// can remove this line if pass singular by value
        return ;
    }
};