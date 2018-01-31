

/*
Leetcode 671. Second Minimum Node In a Binary Tree

Related Topics 
Tree 
Similar Questions 
Kth Smallest Element in a BST

Next challenges: Kth Smallest Element in a BST

Test Cases:
[2,2,5,null,null,5,7]
[2,2,2]
[1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1]

Runtime: 3 ms
Your runtime beats 0.77 % of cpp submissions. which is within majority

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
    int findSecondMinimumValue(TreeNode* root) {
        // 2nd UNIQUE value
        if(!root)   return -1;
        vector<int> vc={root->val};
        vector<TreeNode*> vt={root}, vu;
        TreeNode* tr;
        
        while(!vt.empty()){
            vu.clear();
            for(int i=0; i<vt.size(); i++){
                if(vc.size()==1&&vc[0]<vt[i]->val)  vc.push_back(vt[i]->val);
                if(vc.size()==2&&vt[i]->val<vc[1]&&vt[i]->val!=vc[0])    vc[1]=vt[i]->val;
                    
                if(vt[i]->val<=vc.back()&&vt[i]->right){
                    vu.push_back(vt[i]->right);
                    vu.push_back(vt[i]->left);
                }
            }
            
            if(vu.empty()) break;
            vt.clear();
            for(int i=0; i<vu.size(); i++){
                if(vc.size()==1&&vc[0]<vu[i]->val)  vc.push_back(vu[i]->val);
                if(vc.size()==2&&vu[i]->val<vc[1]&&vu[i]->val!=vc[0])    vc[1]=vu[i]->val;
                
                if(vu[i]->val<=vc.back()&&vu[i]->right){
                    vt.push_back(vu[i]->right);
                    vt.push_back(vu[i]->left);
                }
            }           
        }
        
        return 1<vc.size()?vc[1]:-1;
    }
};
