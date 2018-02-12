

/*
Leetcode 508. Most Frequent Subtree Sum

Related Topics 
Hash Table, Tree 
Similar Questions 
Subtree of Another Tree

Next challenges: Subtree of Another Tree

Test Case:
[5,2,-3]

Runtime: 17 ms
Your runtime beats 33.04 % of cpp submissions.

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int mx=0;
        vector<int> rt;
        unordered_map<int,int> um;
        
        findFeq(root, um);
        
        for(unordered_map<int,int>::iterator umi=um.begin(); umi!=um.end(); umi++){
            mx=mx<umi->second?umi->second:mx;
            //cout<<umi->first<<" "<<umi->second<<endl;
        }
        
        for(unordered_map<int,int>::iterator umi=um.begin(); umi!=um.end(); umi++){
            if(umi->second==mx) rt.push_back(umi->first);
        }        
        
        return rt;
    }
    
    int findFeq(TreeNode* root, unordered_map<int,int>& um){
        // DFS, post-order traversal; hash_table
        if(!root)   return 0;
        int l,r,sum;
        l=findFeq(root->left, um);
        r=findFeq(root->right, um);
        sum=l+r+root->val;
        
        unordered_map<int,int>::iterator umi=um.find(sum);
        if(umi!=um.end())   umi->second+=1;
        else    um.emplace(sum, 1);
        
        return sum;
    }
};