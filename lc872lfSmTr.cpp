
/*
Leetcode 872. Leaf-Similar Trees

Weekly Contest 94:166 / 4541 @Jul 21, 2018

Test Case: 
[3,5,1,6,2,9,8,null,null,7,4]
[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]

Runtime: 0 ms

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> v1, v2;
        v1=dfs( root1);
        v2=dfs( root2);
        //for(auto e:v1)  cout<<e->val<<" ";
        
        if(v1.size()!=v2.size())    return false;
        
        for( int i=0; i<v1.size(); i++){
            if(v1[i]->val!=v2[i]->val)  return false;
        }
        
        return true;
    }
    
    vector<TreeNode*> dfs( TreeNode* root1){
        vector<TreeNode*> v, rt;
        if(!root1)   return rt;
        v.push_back(root1);
        TreeNode * tr;
        
        while(!v.empty()){
            tr=v.back();
            v.pop_back();
            
            if(tr->left){
                v.push_back(tr->left);
                if(tr->right)   v.push_back(tr->right);
            }else{
                if(tr->right)   v.push_back(tr->right);
                else    rt.push_back(tr);
            }
        }
        
        return rt;
    }
};
