
/*
Leetcode 173. Binary Search Tree Iterator

Related Topics 
Stack, Tree, Design 
Similar Questions 
Binary Tree Inorder Traversal, Flatten 2D Vector, Zigzag Iterator, 
Peeking Iterator, Inorder Successor in BST

Next challenges: Flatten 2D Vector, Zigzag Iterator, 
Peeking Iterator, Inorder Successor in BST

Test Cases:
[]
[4,2,6,1,3,5,7]
[6,4,8,2,5,7,10,1,3,null,null,null,null,9,11]

Runtime: 25 ms
Your runtime beats 12.54 % of cpp submissions.
Runtime: 20 ms
Your runtime beats 21.70 % of cpp submissions.

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        // next smallest==next larger
        while(root){
            vc.push_back(root);
            root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        // return this smallest
        if(vc.empty())  return false;
        min=vc.back()->val;
        
        /// push next larger element
        TreeNode* tr=vc.back();
        vc.pop_back();
        if(tr->right){
            tr=tr->right;
            while(tr){
                vc.push_back(tr);
                tr=tr->left;
            }
        }
        
        return true;
    }

    /** @return the next smallest number */
    int next() {
        return min;
    }
    
protected:
    vector<TreeNode*> vc;
    int min;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
