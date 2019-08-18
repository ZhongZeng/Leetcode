/*
1161. Maximum Level Sum of a Binary Tree

Companies	Google
Related Topics	Graph; Suggested: Binary Tree, Breadth-first Search 

Test Case:
[1,7,0,7,-8,null,null]

Runtime: 240 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 78.7 MB
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
    int maxLevelSum(TreeNode* root) {
        // BFS, O(n) time; easy
        if(!root)   return 0;
        int lv=1, vl=root->val;
        vector<TreeNode*> vn={root};
        
        for( int i=1; !vn.empty(); i++){
            vector<TreeNode*> un;
            int sum=0;
            for( int j=0; j<vn.size(); j++){// corner case: level below last level
                sum+=vn[j]->val;
                if(vn[j]->left) un.push_back(vn[j]->left);
                if(vn[j]->right)un.push_back(vn[j]->right);
            }
            if(vl<sum){
                lv=i;
                vl=sum;
            }
            vn=un;
        }
        
        return lv;
    }
};