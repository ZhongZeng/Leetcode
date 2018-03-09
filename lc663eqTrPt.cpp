
/*
Leetcode 663. Equal Tree Partition

Companies 
Amazon 
Related Topics 
Tree 

Next challenges: Verify Preorder Sequence in Binary Search Tree, 
Path Sum III, Path Sum IV

Test Cases:
[5,10,10,null,null,2,3]
[1,2,10,null,null,2,20]
[0,-1,1]
[]

Runtime: 27 ms
Your runtime beats 54.55 % of cpp submissions.
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
    bool checkEqualTree(TreeNode* root) {
        // DFS, post-order traversal 
        if(!root)   return false;
        int sum=0, tg;
        bool eq=false;
        TreeNode* tr;
        vector<TreeNode*> vt={root};
        while(!vt.empty()){
            sum+=vt.back()->val;
            tr=vt.back();
            vt.pop_back();
            if(tr->left)    vt.push_back(tr->left);
            if(tr->right)   vt.push_back(tr->right);
        }
        
        if(sum%2!=0)    return false;
        else    tg=sum>>1;
        
        pstDFS(root->left, eq, tg);
        pstDFS(root->right, eq, tg);
        // pstDFS(root->left, eq, tg);// WRONG
        
        return eq;
    }
    
    int pstDFS(TreeNode* root, bool& eq, int& tg){
        if(eq)  return -1;
            
        if(!root)   return 0;
        int l, r;
        l=pstDFS(root->left, eq, tg);
        r=pstDFS(root->right, eq, tg);
        
        if(root->val+l+r==tg)   eq=true;
        
        return root->val+l+r;
    }
};
