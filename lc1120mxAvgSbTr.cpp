/*
1120. Maximum Average Subtree

Companies	Amazon
Related Topics	Tree, Depth-first Search 

Test Cases:
[5,6,1]
[2,null,1]

Runtime: 12 ms
Memory Usage: 22.1 MB
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
    double maximumAverageSubtree(TreeNode* root) {
        // post-order DFS; O(n) time&space
        double mx=-1;// b/c value of nodes in [1,5000]
        dfs( root, mx);
        return mx;
    }
    
    pair<int,int> dfs( TreeNode * tr, double& mx){// sum, no. of nodes
        if(!tr)    return make_pair(0,0);
        pair<int,int> pr1=dfs(tr->left, mx), pr2=dfs(tr->right, mx);// dfs
        
        int sum=pr1.first+pr2.first+tr->val, num=pr1.second+pr2.second+1;
        double avg=sum*1.0/num;
        if(mx<avg)  mx=avg;
        
        return make_pair(sum, num);
    }
};