
/*
Leetcode 437. Path Sum III

Next challenges: Unique Binary Search Trees, 
Construct Binary Tree from Inorder and Postorder Traversal, Find Duplicate Subtrees

Related Topics 
Tree
Similar Questions 
Path Sum, Path Sum II, Path Sum IV, Longest Univalue Path

Test Cases:
[10,5,-3,3,2,null,11,3,-2,null,1]
8
[]
1
[1]
0
[5,4,8,11,null,13,4,7,2,null,null,5,1]
22
[0,1,1]
1

Runtime: 15 ms
Your runtime beats 91.59 % of cpp submissions.

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
    int pathSum(TreeNode* root, int sum) {
        // hash table, DFS, DP, recursion: prefix solution, O(n)
        if(!root)   return 0;
        int rt=0, ps=0;
        unordered_map<int,int> um;
        
        dfs(ps, root, um, rt, sum);
        
        return rt;
    }
    
    void dfs(int& ps, TreeNode* tr, unordered_map<int,int>& um, int& rt, int& sum){
        // path sum, tree node, prefix path sum, target path sum 
        ps+=tr->val;
        
        // Find Target 
        unordered_map<int,int>::iterator umi=um.find(ps-sum);
        if(umi!=um.end())   rt+=umi->second;
        rt+=ps!=sum?0:1;// this is important         
        
        // Emplace Prefix Sum: this must be after Find Target
        umi=um.find(ps);
        if(umi!=um.end())   umi->second+=1;
        else    um.emplace(ps, 1);
        
        // DFS
        if(tr->left)    dfs(ps, tr->left, um, rt, sum);
        if(tr->right)   dfs(ps, tr->right, um, rt, sum);
        
        um.find(ps)->second-=1;
        ps-=tr->val;
        
        return ;
    }
};
