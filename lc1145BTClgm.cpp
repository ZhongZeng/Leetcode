/*
1145. Binary Tree Coloring Game

Companies	Google
Related Topics	Tree, Depth-first Search 

Test Cases:
[1,2,3,4,5,6,7,8,9,10,11]
11
3
[1,2,3]
3
3

Runtime: 0 ms
Memory Usage: 11.9 MB
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // I've seen a similar problem in Leetcode
        // given 2 nodes, there is only 1 path b/t 2 nodes 
        // the 2nd player must choose a node next to the node that the 1st player choose: parent, left/right child
        vector<int> vc;// sum of left child, right child
        countNode( root, x, vc);
        return (vc[0]>n-vc[0])||(vc[1]>n-vc[1])||(n-vc[0]-vc[1]-1>vc[0]+vc[1]+1);
    }
    
protected:
    int countNode( TreeNode * tr, int& x, vector<int>& vc){
        if(tr==NULL||0<vc.size())    return 0;
        int lf=countNode(tr->left, x, vc), rg=countNode(tr->right, x, vc);
        if(tr->val==x)  vc={lf, rg};
        return lf+rg+1;
    }
};