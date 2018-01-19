

/*
Leetcode 637. Average of Levels in Binary Tree


Related Topics 
Tree
Similar Questions 
Binary Tree Level Order Traversal, Binary Tree Level Order Traversal II

Next challenges: Binary Tree Level Order Traversal, 
Binary Tree Level Order Traversal II

Test Case:
[3,9,20,15,7]
[2147483647,2147483647,2147483647]
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2147483647,2147483647,2147483647,2147483643,2147483645,2147483646,2147483646,2147483624,2147483646,2147483647,2147483646,2147483647,2147483647,2147483631,2147483647,2147483647,2147483647,2147483647,2147483631,2147483647,2147483647,2147483647,2147483647,2147483646,2147483646,2147483614,2147483646,2147483647,2147483646,2147483647,2147483646,2147483647,2147483646,2147483647,2147483646,2147483647,2147483646,2147483647,2147483646,2147483647,2147483646,2147483647,2147483646,2147483647,2147483646,2147483647,2147483646,2147483647,2147483644,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483644,2147483647,2147483647,2147483642,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483636,2147483647,2147483647,2147483647,2147483647,2147483647,2147483647,2147483642,2147483642,2147483647,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483647,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483647,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,2147483642,-2147483647,-2147483647,-2147483647,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483638,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483643,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483643,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483643,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483643,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483643,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483642,-2147483643,-2147483642,-2147483642,-2147483642,-2147483642,-2147483598,-2147483647,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483645,-2147483647,-2147483647,-2147483647,-2147483647,-2147483647,-2147483647,-2147483647,-2147483647,-2147483647,-2147483647,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483644,-2147483600,-2147483646,-2147483646,-2147483646,-2147483646,-2147483646,-2147483646,-2147483646,-2147483646,-2147483646,-2147483646,-2147483646,-2147483647,-2147483647,-2147483525,-2147483647,-2147483647,-2147483644,-2147483647,-2147483647,-2147483647,-2147483646,-2147483647,-2147483336]

Runtime: 20 ms
Your runtime beats 15.54 % of cpp submissions.

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
    vector<double> averageOfLevels(TreeNode* root) {
        // BFS, O(n) time
        double sum;
        vector<double> ag;
        vector<TreeNode*> vb, vc;
        vb.push_back(root);
        
        while(!vb.empty()){
            vc.clear();
            sum=0;
            for(int i=0; i<vb.size(); i++){
                sum+=10.0*vb[i]->val/vb.size();
                //cout<<sum<<" ";
                if(vb[i]->left!=NULL)    vc.push_back(vb[i]->left);
                if(vb[i]->right!=NULL)   vc.push_back(vb[i]->right);
            }
            ag.push_back(sum/10.0);
            //cout<<endl<<vb.size()<<endl;
            
            if(vc.empty())  return ag;
            vb.clear();
            sum=0;
            for(int i=0; i<vc.size(); i++){
                sum+=10.0*vc[i]->val/vc.size();
                //cout<<sum<<" ";
                if(vc[i]->left!=NULL)    vb.push_back(vc[i]->left);
                if(vc[i]->right!=NULL)   vb.push_back(vc[i]->right);
            }
            ag.push_back(sum/10.0); // trick I used previously
            //cout<<endl<<vc.size()<<endl;
        }
        
        return ag;
    }
};
