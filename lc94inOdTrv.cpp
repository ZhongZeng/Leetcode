

/*
Leetcode 94. Binary Tree Inorder Traversal


Next challenges: Validate Binary Search Tree, Binary Tree Postorder Traversal, 
Binary Search Tree Iterator, Kth Smallest Element in a BST, 
Closest Binary Search Tree Value II, Inorder Successor in BST

Related Topics 

Similar Questions 
Validate Binary Search Tree, Binary Tree Preorder Traversal, 
Binary Tree Postorder Traversal, Binary Search Tree Iterator, 
Kth Smallest Element in a BST, Closest Binary Search Tree Value II, 
Inorder Successor in BST

Test Cases:
[1,null,2,3]
[1,null,2,3,4,5,null,8]

Runtime: 3 ms
Your runtime beats 0.51 % of cpp submissions. 

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rt;
        if(!root)   return rt;
        
        TreeNode* tr;
        vector<TreeNode*> vt={root};
        vector<int> vc={0};
        while(!vc.empty()){
            tr=vt.back();
            if(vc.back()==0){
                vt.pop_back();
                vc.pop_back();
                if(tr->right){
                    vt.push_back(tr->right);
                    vc.push_back(0);
                }
                vt.push_back(tr);
                vc.push_back(1);
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
// Runtime: 3 ms
// Your runtime beats 0.51 % of cpp submissions. which is within majority  
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		// recursion 
        vector<int> vc;
        if(!root)   return vc;
        
        if(root->left)  inorderTraversal(root->left, vc);
        vc.push_back(root->val);
        if(root->right) inorderTraversal(root->right, vc);
        
        return vc;
    }
    
    void inorderTraversal(TreeNode* root, vector<int> & vc){
        if(root->left)  inorderTraversal(root->left, vc);
        vc.push_back(root->val);
        if(root->right) inorderTraversal(root->right, vc);        
        
        return ;
    }
    
};
*/