

/*

Leetcode 538. Convert BST to Greater Tree

Related Topics 
Tree

Next challenges: Construct Binary Tree from Inorder and Postorder Traversal, 
Serialize and Deserialize Binary Tree, Find Mode in Binary Search Tree

Test Cases:
[5,2,13]
[13,11,20,10,12,null,22]

Runtime: 40 ms
Your runtime beats 34.38 % of cpp submissions.

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
    TreeNode* convertBST(TreeNode* root) {
        // in-order traversal
        if(!root)   return root;
        int sum=0;
        TreeNode* tr=root;
        vector<TreeNode*> vt={root};
        vector<int> vv={0};
        
        while(!vt.empty()){
            if(vv.back()==0){
                tr=vt.back();
                vt.pop_back();
                vv.pop_back();
                if(tr->left){
                    vt.push_back(tr->left);
                    vv.push_back(0);
                }
                vt.push_back(tr);
                vv.push_back(1);
                if(tr->right){
                    vt.push_back(tr->right);
                    vv.push_back(0);
                }
            }else{
                sum+=vt.back()->val;
                vt.back()->val=sum;
                vt.pop_back();
                vv.pop_back();
            }
        }
        
        
        return root;
    }
};
