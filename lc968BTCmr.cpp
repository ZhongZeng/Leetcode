/*
968. Binary Tree Cameras

Related Topics: Dynamic Programming, Tree, Depth-first Search, Greedy (suggested)

Test Cases:
[0]
[0,0,null,0,0]
[0,0,null,0,null,0,null,null,0]
[0,0,0,null,null,null,0]

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
    int minCameraCover(TreeNode* root) {
        // greedy(put camera as at higher level/closer to root ap)+DFS, O(n) time, O(h) space; or DP; brute force to costly 
        int sum=0;
        
        if(dfs(root,sum)==0)   sum++;
        
        return sum;
    }
    
    int dfs(TreeNode * tr, int& sum){// post-order DFS; no camera: 0: not monitored, 1:monitored ; 2:camera 
        if(!tr) return 1;
        
        int l=dfs(tr->left,sum), r=dfs(tr->right,sum);
        if(l==0||r==0){
            sum++;
            return 2;
        }else if(l==2||r==2){
            return 1;
        }else{
            return 0;
        }
        
        return -1;// won't be triggered
    }
};