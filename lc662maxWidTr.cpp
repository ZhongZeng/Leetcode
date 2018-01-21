

/*
Leetcode 662. Maximum Width of Binary Tree

Related Topics 
Tree

Next challenges: Recover Binary Search Tree, 
Most Frequent Subtree Sum, Convert BST to Greater Tree

Test Cases:
The representation of tree in test cases only considers children of not-null nodes.
[]
[1]
[1,3,2,5,3,null,9]
[1,3,null,5,3]
[1,3,2,5]
[1,3,2,5,null,null,9,0,null,null,7]

Runtime: 8 ms
Your runtime beats 21.90 % of cpp submissions.

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
    int widthOfBinaryTree(TreeNode* root) {
        // BFS
        // this should be easy
        if(!root)   return 0;
        int len=0, lf, rt;
        vector<TreeNode*> vc, vd;
        vector<int> lc, ld;
        vc.push_back(root);
        lc.push_back(0);
        
        while(!vc.empty()){
            len=len<lc.back()-lc[0]+1?lc.back()-lc[0]+1:len;
            vd.clear();
            ld.clear();
            for(int i=0; i<vc.size(); i++){
                if(vc[i]->left){
                    vd.push_back(vc[i]->left);
                    ld.push_back((lc[i]<<1)+1);
                }
                if(vc[i]->right){
                    vd.push_back(vc[i]->right);
                    ld.push_back((lc[i]<<1)+2);
                }
            }
            
            if(vd.size()<1) break;
            len=len<ld.back()-ld[0]+1?ld.back()-ld[0]+1:len;
            vc.clear();
            lc.clear();
            for(int i=0; i<vd.size(); i++){
                if(vd[i]->left){
                    vc.push_back(vd[i]->left);
                    lc.push_back((ld[i]<<1)+1);
                }
                if(vd[i]->right){
                    vc.push_back(vd[i]->right);
                    lc.push_back((ld[i]<<1)+2);
                }
            }
        }
        
        return len;
    }
};
