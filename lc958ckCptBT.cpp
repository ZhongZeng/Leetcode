/*
958. Check Completeness of a Binary Tree

Related Topic:	Tree 

Test Cases:
[1]
[1,2,3,4,5,6]
[1,2,3,4,5,null,7]

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
    bool isCompleteTree(TreeNode* root) {
        if(!root)   return true;
        int i, j, h=0;
        TreeNode * tr;
        vector<TreeNode*> vt={root}, ut;
        for( tr=root; tr; tr=tr->left)  h++;
        
        for( i=1; i<h-1; i++){// 1 to 3rd last row
            ut.clear();
            for( int j=0; j<vt.size(); j++){
                if(vt[j]->left)    ut.push_back(vt[j]->left);
                else    return false;
                if(vt[j]->right)    ut.push_back(vt[j]->right);
                else    return false;
            }
            vt=ut;
        }
        
        ut.clear();// 2nd last row 
        for( j=0; j<vt.size(); j++){
            if(vt[j]->left){
                ut.push_back(vt[j]->left);
            }else{
                if(vt[j]->right)    return false;
                break;
            }
            if(vt[j]->right)ut.push_back(vt[j]->right);
            else    break;
        }
        for( j++; j<vt.size(); j++){
            if(vt[j]->left) return false;
            if(vt[j]->right)return false;      
        }
        
        for( j=0; j<ut.size(); j++){// last row 
            if(ut[j]->left) return false;
            if(ut[j]->right)return false;            
        }
        
        return true;
    }
};
