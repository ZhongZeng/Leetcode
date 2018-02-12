
/*
783. Minimum Distance Between BST Nodes

Weekly Contest 71  Feb 10, 2018

Test Cases:
[4,2,6,1,3,null,null]
[7,3,15,1,5,11,17,null,null,null,null,8]

Runtime: 4 ms

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
    int minDiffInBST(TreeNode* root) {
        int mn=root->right?root->right->val-root->val:root->val-root->left->val;
        minDif(root, mn, root->val+1);// think of root as the left child of a hypo node
        return mn;
    }
    
    int minDif(TreeNode* tr, int& mn, int ser){
        // O(n) time, O(1) space
        // DFS, in-order traversal 
        if(tr->left){
            ser=minDif(tr->left, mn, ser);
            mn=tr->val-ser<mn?tr->val-ser:mn;
        }else{
            if(ser<=tr->val)  mn=tr->val-ser<mn?tr->val-ser:mn;
        }
        
        if(tr->right){
            int r=minDif(tr->right, mn, tr->val);
            return r;
        }else{
            return tr->val;
        }  
    }
    
};

/*
// Runtime: 4 ms
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int mn=root->left?root->val-root->left->val:root->right->val-root->val;
        vector<int> vc;
        
        minDis(root, mn, vc);      
        
        return mn;
    }
    
    void minDis(TreeNode* tr, int& mn, vector<int>& vc){
        
        if(tr->left)    minDis(tr->left, mn, vc);
        if(!vc.empty()) mn=tr->val-vc.back()<mn?tr->val-vc.back():mn;
        vc.push_back(tr->val);
        if(tr->right)   minDis(tr->right, mn, vc);
        
        return ;
    }
};
*/