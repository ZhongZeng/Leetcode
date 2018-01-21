

/*
Leetcode 623. Add One Row to Tree

Related Topics 
Tree

Next challenges: Path Sum II, Verify Preorder Sequence in Binary Search Tree, 
Maximum Width of Binary Tree

Test Cases:
[4,2,6,3,1,5]
1
1
[4,2,6,3,1,5]
1
2
[4,2,6,3,1,5]
1
3

Runtime: 21 ms
Your runtime beats 23.04 % of cpp submissions.

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // BFS
        if(d==1){
            TreeNode* tr=new TreeNode(v);
            tr->left=root;
            return tr;
        }
        
        int i=1;
        vector<TreeNode*> vc, vd;
        vc.push_back(root);
        
        while(++i<d){           
            for(int j=0; j<vc.size(); j++){
                if(vc[j]->left) vd.push_back(vc[j]->left);
                if(vc[j]->right)vd.push_back(vc[j]->right);
            }
            vc.clear();
            
            if(d<=++i)  break;
            
            for(int j=0; j<vd.size(); j++){
                if(vd[j]->left) vc.push_back(vd[j]->left);
                if(vd[j]->right)vc.push_back(vd[j]->right);
            }            
            vd.clear();
        }
        
        if(vc.empty())  addRow(vd, v);
        else    addRow(vc, v);
        
        return root;
    }

protected:    
    void addRow(vector<TreeNode*>& vd, int v){
        for(int j=0; j<vd.size(); j++){
            TreeNode* tr1=new TreeNode(v);
            TreeNode* tr2=new TreeNode(v);
            tr1->left=vd[j]->left;
            tr2->right=vd[j]->right;
            vd[j]->left=tr1;
            vd[j]->right=tr2;
        }        
        return ;
    }
};
