

/*

Leetcode 655. Print Binary Tree

Related Topics 
Tree 

Next challenges: Binary Tree Maximum Path Sum, 
Kth Smallest Element in a BST, Closest Leaf in a Binary Tree

Test Cases:
[1,2]
[1,2,4,null,4,null,5]

Runtime: 4 ms
Your runtime beats 11.55 % of cpp submissions.

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
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root)   return {};
        int r=0, c=1, t;
        vector<TreeNode*> vc={root}, vd;
        vector<int> lc, ld;
        // BFS
        while(!vc.empty()){
            vd.clear();
            for(int i=0; i<vc.size(); i++){
                if(vc[i]->right)vd.push_back(vc[i]->right);
                if(vc[i]->left) vd.push_back(vc[i]->left);
            }
            r++;
            c*=2;

            if(vd.empty())  break;
            vc.clear();
            for(int i=0; i<vd.size(); i++){
                if(vd[i]->right)vc.push_back(vd[i]->right);
                if(vd[i]->left) vc.push_back(vd[i]->left);
            }
            r++;
            c*=2;
        }
        
        vector<string> vs(c-1, "");
        vector<vector<string>> rt(r, vs);
        // cout<<r<<" "<<c<<endl;
        // for(auto ele:rt){for(auto elf:ele)   cout<<elf<<" "; cout<<endl;}    
        // BFS
        vc={root};
        lc={(c-1)/2};
        t=c/4;
        r=0;
        
        while(!vc.empty()){
            vd.clear();
            ld.clear();
            for(int i=0; i<vc.size(); i++){
                rt[r][lc[i]]=to_string(vc[i]->val);
                if(vc[i]->right){
                    vd.push_back(vc[i]->right);
                    ld.push_back(lc[i]+t);
                }
                if(vc[i]->left){
                    vd.push_back(vc[i]->left);
                    ld.push_back(lc[i]-t);
                }
            }
            r++;
            t/=2;

            if(vd.empty())  break;
            vc.clear();
            lc.clear();
            for(int i=0; i<vd.size(); i++){
                rt[r][ld[i]]=to_string(vd[i]->val);
                if(vd[i]->right){
                    vc.push_back(vd[i]->right);
                    lc.push_back(ld[i]+t);
                }
                if(vd[i]->left){
                    vc.push_back(vd[i]->left);
                    lc.push_back(ld[i]-t);
                }
            }
            r++;
            t/=2;
        }
        
        return rt;
    }
};
