/*
1008. Construct Binary Search Tree from Preorder Traversal

Related Topics:	Tree 

Test Case:
[8,5,1,7,10,12]

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // BST, DFS, tree; preorder.size() in [1,100]; distinct values in BST 
        TreeNode * rt=new TreeNode(preorder[0]), * tp;
        vector<TreeNode*> ac={rt};// path of larger ancestors 
        
        for( int i=1; i<preorder.size(); i++){
            TreeNode * nt=new TreeNode(preorder[i]);
            //cout<<nt->val<<": ";
            
            if(nt->val < ac.back()->val){
                ac.back()->left=nt;
                ac.push_back(nt);
            }else{
                while( 0<ac.size() && ac.back()->val < nt->val){
                    tp=ac.back();
                    ac.pop_back();
                    //cout<<tp->val<<", ";
                }
                tp->right=nt;
                ac.push_back(nt);// no need to push_back tp b/t nt, b/c tp has nt as right child
            }
            //cout<<endl;
        }
        
        return rt;
    }
};