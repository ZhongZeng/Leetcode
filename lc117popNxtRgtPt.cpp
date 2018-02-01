
/*
Leetcode 117. Populating Next Right Pointers in Each Node II


Test Cases:
{0,2,4,1,#,3,-1,5,1,#,6,#,8}
{1,2,3}
{2,0,5,#,-5,-1,#,#,5,5,7,#,#,0,-3,-9,#,#,8}

Related Topics 
Tree, Depth-first Search
Similar Questions 
Populating Next Right Pointers in Each Node

Runtime: 40 ms
Your runtime beats 5.42 % of cpp submissions.

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
        // BFS, O(n) time, O(1) space
        if(!root)   return;
        
        TreeLinkNode* tr=root, * nc=nextLevel(tr), * nx;
        
        while(tr!=NULL){
            nx=nextNode(tr);
            if(nx){
                if(tr->left){
                    if(tr->right){
                        tr->left->next=tr->right;
                        tr->right->next=nx->left!=NULL?nx->left:nx->right;
                    }else{
                        tr->left->next=nx->left!=NULL?nx->left:nx->right;
                    }    
                }else{
                    if(tr->right){
                        tr->right->next=nx->left!=NULL?nx->left:nx->right;
                    }
                }                
                tr=nx;
            }else{
                if(tr->left!=NULL&&tr->right!=NULL)  tr->left->next=tr->right;
                tr=nc;
                nc=nextLevel(tr);
            }
        }
        
        return ;
    }

protected:    
    TreeLinkNode * nextNode(TreeLinkNode * tr){// tr!=NULL
        TreeLinkNode * rt=tr->next;
        while(rt){
            if(rt->left!=NULL||rt->right!=NULL) return rt;
            rt=rt->next;
        }
        return rt;
    }
    
    TreeLinkNode * nextLevel(TreeLinkNode * tr){// tr!=NULL
        TreeLinkNode * rt=tr;
        while(rt){
            if(rt->left&&(rt->left->left!=NULL||rt->left->right!=NULL))     return rt->left;
            if(rt->right&&(rt->right->left!=NULL||rt->right->right!=NULL))  return rt->right;
            rt=rt->next;
        }
        return rt;
    }
};
