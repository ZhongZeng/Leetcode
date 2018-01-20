
/*
Leetcode 111. Minimum Depth of Binary Tree

Related Topics 
Tree, Depth-first Search, Breadth-first Search 
Similar Questions 
Binary Tree Level Order Traversal, Maximum Depth of Binary Tree 

Test Cases:
[]
[1]
[1,2]
[1,2,3]
[1,null,2]
[1,2,null,4]
[1,2,3,4,null,5,6]
[1,2,3,4,5,6,7,8]

Runtime: 6 ms
You are here! 
Your runtime beats 54.15 % of cpp submissions.

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
    int minDepth(TreeNode* root) {   
        // leaf is defiend as the node whose left and right are both NULL  
        if(root==NULL)  return 0;
        queue< TreeNode *> qt;
        queue< int> qd;
        TreeNode * tn=root;
        int d=0, len=0;
        qt.push(tn);
        qd.push(d);// d: depth of current node 
            
        while( qt.empty()!=true ){                        
            tn = qt.front();
            d = qd.front();            
                if( tn->right!=NULL){ 
                    qt.push( tn->right );
                    qd.push( d+1);                
                    if( tn->left!=NULL){
                        qt.push( tn->left );  
                        qd.push( d+1);                     
                    }                   
                }else{
                    if( tn->left!=NULL){
                        qt.push( tn->left );  
                        qd.push( d+1);
                    }else{
                        if(len!=0){
                            len = len<d+1 ? len:d+1;
                        }else{
                            len = d+1;
                        }
                    }                                        
                }                
            qt.pop();     
            qd.pop();            
        }       
        
        return len;
    }
};
