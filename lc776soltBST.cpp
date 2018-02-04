
/*
776. Split BST

Weekly Contest 70  

Test Cases: 
[4,2,6,1,3,5,7]
2
[4,1,6,-1,2,5,7]
3
[4,2,6,1,3,5,7]
5


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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
		// Tree, DFS
        vector<TreeNode*> rt(2,NULL), nd;
        if(!root)   return rt;
        TreeNode* tr=root;
        
        while(tr){
            nd.push_back(tr);
            if(V<tr->val){
                tr=tr->left;
            }else{ // tr->val<=V
                tr=tr->right;
            }
        }
        
        for(int i=nd.size()-1; -1<i; i--){
            if(V<nd[i]->val){
                nd[i]->left=rt[1];
                rt[1]=nd[i];
            }else{
                nd[i]->right=rt[0];
                rt[0]=nd[i];
            }
        }
            
        return rt;
    }
};
