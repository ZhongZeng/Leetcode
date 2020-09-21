/*
510. Inorder Successor in BST II

Medium
Companies	Microsoft, Quip (Salesforce)
Related Topics	Tree

Test Cases:
[2,1,3]
1
[5,3,6,2,4,null,null,1]
6
[15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9]
15
[15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9]
13
[0]
0
Runtime: 44 ms, faster than 19.83% of C++ online submissions for Inorder Successor in BST II.
Memory Usage: 11.5 MB, less than 55.59% of C++ online submissions for Inorder Successor in BST II.
Next challenges: Construct Binary Tree from Preorder and Postorder Traversal,
Smallest Common Region, Clone N-ary Tree
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right){
            Node * s=node->right;
            while( s->left) s=s->left;
            return s;
        }else if(node->parent){
            Node * s=node->parent;
            if(s->left==node){
                return s;
            }else{
                for( ; s->parent; s=s->parent){
                    if(s->parent->left==s)  return s->parent;
                }
                return NULL;
            }
        }else{
            return NULL;
        }
    }
};