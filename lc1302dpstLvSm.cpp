/*
1302. Deepest Leaves Sum

Companies	Google
Related Topics	Tree, Depth-first Search

Test Case:
[1,2,3,4,5,null,6,7,null,null,null,null,8]

Runtime: 40 ms, faster than 96.27% of C++ online submissions for Deepest Leaves Sum.
Memory Usage: 29.1 MB, less than 100.00% of C++ online submissions for Deepest Leaves Sum.
Next challenges: Reconstruct Itinerary, All Paths from Source Lead to Destination,
Remove Boxes
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
    int deepestLeavesSum(TreeNode* root) {
		// DFS; this should be easy 
        int deepest=0, sum=0;
        deepestLeavesSum( root, 1, deepest, sum);
        return sum;
    }
    
protected:
    void deepestLeavesSum( TreeNode * root, int depth, int & deepest, int & sum){
        if(root->left){
            deepestLeavesSum( root->left, depth+1, deepest, sum);
            if(root->right)
                deepestLeavesSum( root->right, depth+1, deepest, sum);
        }else{
            if(root->right){
                deepestLeavesSum( root->right, depth+1, deepest, sum);
            }else{
                if(deepest<depth){
                    deepest=depth;
                    sum=root->val;
                }else if(deepest==depth){
                    sum+=root->val;
                }
            }
        }
        return ;
    }
};