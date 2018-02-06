

/*
Leetcode 687. Longest Univalue Path

Related Topics 
Tree, Recursion 
Similar Questions 
Binary Tree Maximum Path Sum, Count Univalue Subtrees, Path Sum III

Next challenges: Binary Tree Maximum Path Sum, Count Univalue Subtrees, Path Sum III

Test Cases:
[5,4,5,1,1,5]
[1,4,5,4,4,5,null,5]
[4,4,2,4,null,5,6,4]

Runtime: 62 ms
Your runtime beats 82.90 % of cpp submissions.

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
    int longestUnivaluePath(TreeNode* root) {
        // recursion, DFS, tree
        if(!root)   return 0;
        int mx=0, len=uniValue(root, mx);
        
        return mx;
    }
    
protected:    
    int uniValue( TreeNode * tr, int& mx){
        int lf=0, rg=0;
        
        if(tr->left){
            lf=uniValue(tr->left, mx)+1;
            lf=tr->val!=tr->left->val?0:lf;
        }    
        
        if(tr->right){
            rg=uniValue(tr->right, mx)+1;
            rg=tr->val!=tr->right->val?0:rg;
        }    
        
        mx=mx<lf+rg?lf+rg:mx;
        //cout<<tr->val<<" "<<lf<<" "<<rg<<endl;
        
        return lf<rg?rg:lf;
    }
    
};


/*
// Wrong Answer
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)  return 0;
        return longPath(root, 0, 0)-1;
    }
    
protected:    
    int longPath(TreeNode* root, int len, int max){
        // continuous len including this node from root, max including this node
        int l,r; // max length in left&right sub-tree
        if(root->right!=NULL){
            if(root->left!=NULL){
                if(root->right->val!=root->val){
                    if(root->left->val!=root->val){
                        r=longPath(root->right, 1, max);
                        l=longPath(root->left, 1, max);
                        return l<r?r:l;
                    }else{
                        max=len<max?max:len;
                        r=longPath(root->right, 1, max);
                        l=longPath(root->left, len+1, max);
                        return l<r?r:l;
                    }
                }else{
                    if(root->left->val!=root->val){
                        max=len<max?max:len;
                        r=longPath(root->right, len+1, max);
                        l=longPath(root->left, 1, max);
                        return l<r?r:l;
                    }else{
                        max=len<max?max:len;
                        r=longPath(root->right, 0, max);
                        l=longPath(root->left, 0, max);
                        
                        return sumMax(len, r, l)+1;
                    }                    
                }
            }else{ // left==NULL
                if(root->right->val!=root->val){
                    max=len<max?max:len;
                    r=longPath(root->right, 1, max);
                }else{
                    r=longPath(root->right, len+1, max);
                }
                return r;
            }
        }else{ // right==NULL
            if(root->left!=NULL){
                if(root->left->val!=root->val){
                    max=len<max?max:len;
                    r=longPath(root->left, 1, max);
                }else{
                    r=longPath(root->left, len+1, max);
                }
                return r;                
            }else{
                max=len<max?max:len;
                return 1;
            }            
        }
    }
    
    int sumMax(int len, int r, int l){
        if(len<r){
            return r+l;
        }else{
            return len+l;
        }
    }
};
*/
