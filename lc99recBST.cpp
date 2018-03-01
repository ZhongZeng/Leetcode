
/*
Leetcode 99. Recover Binary Search Tree

Next challenges: Number of Connected Components in an Undirected Graph, 
Redundant Connection II, Swim in Rising Water

Related Topics 
Tree, Depth-first Search 

Test Cases:
[2,null,3,1]
[0,1]
[4,6,2,1,3,5,7]

Runtime: 109 ms
Your runtime beats 0.75 % of cpp submissions.
Runtime: 73 ms
Your runtime beats 10.38 % of cpp submissions.
Runtime: 56 ms
Your runtime beats 37.74 % of cpp submissions.

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
    void recoverTree(TreeNode* root) {
        // DFS, in-order traversal like an ascending array; O(n) time, O(h) space
        if(!root)   return ;
        vector<TreeNode*> vc;
        dfsInOd(root, vc);
        
        // swap back values 
        int t=vc[0]->val;
        vc[0]->val=vc.back()->val;
        vc.back()->val=t;
        
        return ;
    }
    
protected:// polymorphism
    TreeNode* dfsInOd(TreeNode* root, vector<TreeNode*>& vc){// root!=NULL; return largest node in the root 
        //cout<<root->val<<" ";
        if(root->left){
            TreeNode * lt=dfsInOd(root->left, vc);
            if(root->val<lt->val){
                vc.push_back(lt);
                vc.push_back(root);
            }
        }
        return root->right!=NULL?dfsInOd(root->right, root, vc):root;
    }
    
    TreeNode* dfsInOd(TreeNode* root, TreeNode * lt, vector<TreeNode*>& vc){// root!=NULL; return largest node in the root 
        //cout<<root->val<<" ";
        if(root->left)  lt=dfsInOd(root->left, lt, vc);
        if(root->val<lt->val){
            vc.push_back(lt);
            vc.push_back(root);
        }
        return root->right!=NULL?dfsInOd(root->right, root, vc):root;
    }
    
};