
/*
Leetcode 654. Maximum Binary Tree

Companies 
Microsoft
Related Topics 
Tree 

Next challenges: Binary Tree Upside Down, 
Count Complete Tree Nodes, Serialize and Deserialize BST

Test Cases:
[3,2,1,6,0,5]

Runtime: 70 ms
Your runtime beats 42.55 % of cpp submissions.

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // Given an integer array with no duplicates.
        // The size of the given array will be in the range [1,1000].
        // tree, stack, DP; O(n) time, each node visited at most twice
        int mx=nums[0];
        vector<TreeNode*> vc;
        TreeNode* tr=new TreeNode(nums[0]), * rt=tr, * tp;
        vc.push_back(tr);
        
        for(int i=1; i<nums.size(); i++){
            TreeNode* tr=new TreeNode(nums[i]);
            
            if(vc.back()->val<nums[i]){// vc.back() is the right most element in nums
                while(!vc.empty()&&vc.back()->val<nums[i]){
                    tp=vc.back();
                    vc.pop_back();
                }
                
                tr->left=tp;
                
                if(0<vc.size()) vc.back()->right=tr;
                else    rt=tr;
                
                vc.push_back(tr);
            }else{
                vc.back()->right=tr;
                vc.push_back(tr);
            }
        }
        
        return rt;
    }
};
