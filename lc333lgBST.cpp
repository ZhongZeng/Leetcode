
/*
Leetcode 333. Largest BST Subtree

Companies 
Microsoft 
Related Topics 
Tree 

Test Cases: 
[4,1,6,null,null,5,null,2]
[10,5,15,1,8,null,7]
[4,2,null,3]
[]

Runtime: 13 ms
Your runtime beats 30.53 % of cpp submissions.

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
    int largestBSTSubtree(TreeNode* root) {
        // post-order DFS; subtree must contain leaf, can't be truncated off leaf 
        if(!root)   return 0;
        int rt=1;
        vector<int> vr, vc;
        vr.push_back(root->val);
        vr.push_back(root->val);
        vr.push_back(1);
        
        if(root->left){
            vc=dfs( root->left, rt);
            if(-1<vc[2]&&vc[1]<root->val)   vr[2]+=vc[2];
            else    vr[2]=-1;
        }

        if(root->right){
            vc=dfs( root->right, rt);
            if(-1<vc[2]&&root->val<vc[0]&&-1<vr[2]) vr[2]+=vc[2];
            else    vr[2]=-1;
        }
        
        rt=rt<vr[2]?vr[2]:rt;
        
        return rt;
    }
    
    vector<int> dfs( TreeNode* r, int& rt){// left child: min, max, children
        vector<int> vr, vc;
        vr.push_back(r->val);
        vr.push_back(r->val);
        vr.push_back(1);
        
        if(r->left){
            vc=dfs( r->left, rt);
            if(-1<vc[2]&&vc[1]<r->val){
                vr[0]=vc[0];
                vr[2]+=vc[2];
            }else{
                vr[2]=-1;
            }
        }

        if(r->right){
            vc=dfs( r->right, rt);
            if(-1<vc[2]&&r->val<vc[0]&&-1<vr[2]){
                vr[1]=vc[1];
                vr[2]+=vc[2];
            }else{
                vr[2]=-1;
            }
        }
        
        rt=rt<vr[2]?vr[2]:rt;
        
        return vr;
    }
};
