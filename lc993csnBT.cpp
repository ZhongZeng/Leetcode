/*
993. Cousins in Binary Tree

Related Topics: Tree; Suggested: Depth-First Search 

Test Cases:
[1,2,3,null,4,null,5]
5
4
[1,2,3,4]
4
3
[1,2,3,null,4]
2
3

Runtime: 8 ms
Memory Usage: 11.7 MB
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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> vc(4,-1);// parent:x,y; depth:x,y 
        return dfs( root, x, y, vc, 0, -1);// corner case: x||y is root
    }
    
    bool dfs(TreeNode* tr, int x, int y, vector<int>& vc, int dp, int pr){// post-order DFS 
        if(!tr) return false;
        
        if(dfs(tr->left, x, y, vc, dp+1, tr->val))    return true;
        if(dfs(tr->right, x, y, vc, dp+1, tr->val))   return true;
        
        if(tr->val==x){
            vc[0]=pr;
            vc[2]=dp;
        }
        if(tr->val==y){
            vc[1]=pr;
            vc[3]=dp;
        }
        
        if(vc[2]!=-1&&vc[3]!=-1)    return (vc[0]!=vc[1])&&(vc[2]==vc[3]);
        
        return false;
    }
};
