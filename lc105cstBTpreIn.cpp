
/*
Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal


Related Topics 
Array, Tree, Depth-first Search 
Similar Questions 
Construct Binary Tree from Inorder and Postorder Traversal

Next challenges: Construct Binary Tree from Inorder and Postorder Traversal

Test Cases:
[3,9,20,15,7]
[9,3,15,20,7]
[1,2,3]
[2,3,1]
[1,2,4,8,5,9,10,3,6,7,11,12]
[8,4,2,9,5,10,1,6,3,11,7,12]

Runtime: 12 ms
Your runtime beats 88.07 % of cpp submissions.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()<1)   return NULL;
        vector<TreeNode*> pr;
        TreeNode * root=new TreeNode(-1);
        TreeNode * pl=root;
        bool lf=true;
        
        for(int i=0,j=0; i<preorder.size(); i++){
            TreeNode * tr=new TreeNode(preorder[i]);
            
            if(preorder[i]!=inorder[j]){
                if(lf){
                    pl->left=tr;
                }else{
                    pl->right=tr;
                    lf=true;
                }    
                pr.push_back(tr);
                pl=tr;
            }else{
                if(lf){
                    pl->left=tr;
                }else{
                    pl->right=tr;
                }
                pl=tr;
                j++;
                while((!pr.empty())&&pr.back()->val==inorder[j]){
                    pl=pr.back();
                    pr.pop_back();
                    j++;
                }
                lf=false;
            }
            
        }
        
        return root->left;
    }
};
