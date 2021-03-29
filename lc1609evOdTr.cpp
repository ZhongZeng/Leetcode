/*
1609. Even Odd Tree

Companies:	JPMorgan 
Related Topics:	Tree 

Runtime: 380 ms	Your runtime beats 11.50 % of cpp submissions.
Memory Usage: 159.6 MB	Your memory usage beats 23.64 % of cpp submissions.
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
    bool isEvenOddTree(TreeNode* root) {
        // BFS 
        if(!root)   return false;
        vector<TreeNode*> nodes={root};
        
        for( bool even=true; !nodes.empty(); even=!even){
            if(even){
                if(nodes[0]->val%2==0)   return false;
                for( int i=1; i<nodes.size(); i++){
                    if(nodes[i]->val%2==0||
                       nodes[i-1]->val>=nodes[i]->val){
                        return false;
                    }
                }
            }else{
                if(nodes[0]->val%2==1)   return false;
                for( int i=1; i<nodes.size(); i++){
                    if(nodes[i]->val%2==1||
                        nodes[i-1]->val<=nodes[i]->val){
                        return false;
                    }
                }
            }
            
            vector<TreeNode*> next_nodes;
            for( int i=0; i<nodes.size(); i++){
                if(nodes[i]->left)
                    next_nodes.push_back(nodes[i]->left);
                if(nodes[i]->right)
                    next_nodes.push_back(nodes[i]->right);
            }
            nodes=next_nodes;
        }
        
        return true;
    }
};