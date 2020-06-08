/*
1430. Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree

Medium
Companies	23&me
Related Topics	Tree

Test Cases:
[8,3,null,2,1,5,4]
[8]
[0,1,0,0,1,0,null,null,1,0,0]
[0,1,0,1]
[0,1,0,0,1,0,null,null,1,0,0]
[0,0,1]
[0,1,0,0,1,0,null,null,1,0,0]
[0,1,1]

*/

/*
Runtime seems randomly normally distributed. 
Runtime: 88 ms, faster than 76.27% of C++ online submissions for Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree.
Memory Usage: 48.9 MB, less than 65.79% of C++ online submissions for Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree.
Runtime: 160 ms, faster than 5.09% of C++ online submissions for Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree.
Memory Usage: 48.8 MB, less than 95.78% of C++ online submissions for Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree.
Next challenges:
Closest Binary Search Tree Value II
Serialize and Deserialize BST
Smallest Common Region
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        // O(n) time; leaf has no children
        if(!root)   return arr.empty();
        return dfs( root, arr, 0);
    }
    
protected:
    bool dfs( TreeNode* tr, vector<int> & arr, int p){// pre-order DFS
        if(p==arr.size())   return false;
        if(tr->val!=arr[p]) return false;
        if(tr->right){
            if(tr->left)    return dfs(tr->left, arr, p+1)||dfs(tr->right, arr, p+1);
            else    return dfs(tr->right, arr, p+1);
        }else{
            if(tr->left)    return dfs(tr->left, arr, p+1);
            else    return p==arr.size()-1;
        }
        return false;
    }
};