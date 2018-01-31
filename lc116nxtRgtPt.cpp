

/*
Leetcode 116. Populating Next Right Pointers in Each Node

Related Topics 
Tree, Depth-first Search 
Similar Questions 
Populating Next Right Pointers in Each Node II, Binary Tree Right Side View

Next challenges: Populating Next Right Pointers in Each Node II

Runtime: 19 ms
Your runtime beats 21.40 % of cpp submissions.

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // I took a look at the hint, using next that you create. 
        // parent's right child or parent's next's left child 
        if(!root)   return;
        TreeLinkNode * tr=root, * nx=root->left;
        
        while(tr->right){
            tr->left->next=tr->right;
            if(tr->next)    tr->right->next=tr->next->left;
            
            if(tr->next){
                tr=tr->next;
            }else{
                tr=nx;
                nx=nx->left;
            }
        }
        
        return;
    }
};
