

/*
Leetcode 108. Convert Sorted Array to Binary Search Tree

Related Topics 
Tree, Depth-first Search 
Similar Questions 
Convert Sorted List to Binary Search Tree

Next challenges: Convert Sorted List to Binary Search Tree

Test Cases:
[-10,-3,0,5,9]
[0,1,2,3,4,5,6]
[0,1,2,3,4,5,6,7]
[]

Runtime: 16 ms
Your runtime beats 19.75 % of cpp submissions. 

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // BST, BFS, recursion
        if(nums.size()<1)   return NULL;
        int b=0, m=nums.size()/2, e=nums.size();
        TreeNode * root=new TreeNode(nums[m]);
        
        if(e!=b){
            construChildren( nums, b, m, e, root);
        }   
        
        return root;
    }
    
    void construChildren(vector<int>& nums, int b, int m, int e, TreeNode * root){
        if(b<m){
            int l=b+(m-b)/2;
            TreeNode * lf=new TreeNode(nums[l]);
            root->left=lf;
            construChildren(nums,b,l,m,lf);
        }
        
        if(m+1<e){
            int r=m+1+(e-m-1)/2;
            TreeNode * rg=new TreeNode(nums[r]);
            root->right=rg;
            construChildren(nums,m+1,r,e,rg);
        }
        
        return ;
    }
};