

/*
Leetcode 145. Binary Tree Postorder Traversal

Related Topics 
Stack, Tree 
Similar Questions 
Binary Tree Inorder Traversal

Next challenges: Path Sum, House Robber III, Path Sum III

Test Cases:
[]
[1,null, 3,2]

Runtime: 3 ms
Your runtime beats 0.60 % of cpp submissions.

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
    vector<int> postorderTraversal(TreeNode* root) {
		// iteration
        // modified from leetcode 94 in-order traversal 
		// this and leetcode 94 should be easy. 
        vector<int> rt;
        if(!root)   return rt;
        
        TreeNode* tr;
        vector<TreeNode*> vt={root};
        vector<int> vc={0};
        while(!vc.empty()){
            tr=vt.back();
            if(vc.back()==0){
                vc.back()=1;
                if(tr->right){
                    vt.push_back(tr->right);
                    vc.push_back(0);
                }
                if(tr->left){
                    vt.push_back(tr->left);
                    vc.push_back(0);
                }
            }else{
                rt.push_back(tr->val);
                vt.pop_back();
                vc.pop_back();
            }
            
        }
        
        return rt;      
    }
};

/*
// Runtime: 2 ms
// Your runtime beats 59.14 % of cpp submissions.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
		// recursion 
		// modified from leetcode 94 in-order traversal 
        vector<int> vc;
        if(!root)   return vc;
        
        if(root->left)  postorderTraversal(root->left, vc);
        if(root->right) postorderTraversal(root->right, vc);
        vc.push_back(root->val);
        
        return vc;        
    }

    void postorderTraversal(TreeNode* root, vector<int> & vc){
        if(root->left)  postorderTraversal(root->left, vc);
        if(root->right) postorderTraversal(root->right, vc);
        vc.push_back(root->val);
        
        return ;
    }    
    
};		
*/
