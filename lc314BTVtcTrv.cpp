
/*
Leetcode 314. Binary Tree Vertical Order Traversal

Companies 
Google, Facebook, Snapchat 
Related Topics 
Hash Table 
Similar Questions 
Binary Tree Level Order Traversal

Test Cases:
[3,9,20,null,null,15,7]
[3,9,8,4,0,1,7]
[3,9,8,4,0,1,7,null,null,null,2,5]

Runtime: 7 ms
Your runtime beats 12.47 % of cpp submissions.

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // left+1, right-1; Hash Table, Tree
        // BFS, from top to bottom, column by column; O(n) time 
        vector<vector<int>> rt;
        if(!root)   return rt;
        unordered_map<int, vector<int>> um;
        unordered_map<int, vector<int>>::iterator umi;
        vector<TreeNode*> vt={root}, vs;
        vector<int> vi={0}, vj;
        
        while(!vt.empty()){
            bfs(um, vt, vi, vs, vj);
            if(vs.empty())  break;
            bfs(um, vs, vj, vt, vi);
        }
        
        int mn=0, mx=0;
        for( umi=um.begin(); umi!=um.end(); umi++){
            if(umi->first<mn)   mn=umi->first;
            if(mx<umi->first)   mx=umi->first;
        }
        
        for( int i=mn; i<mx+1; i++){
            rt.push_back(um.find(i)->second);
        }
        
        return rt;
    }
    
    void bfs(unordered_map<int, vector<int>>& um, vector<TreeNode*>& vt, vector<int>& vi, 
             vector<TreeNode*>& vs, vector<int>& vj){
        vs.clear();
        vj.clear();
        vector<int> vc;
        unordered_map<int, vector<int>>::iterator umi;
        for( int i=0; i<vt.size(); i++){
            umi=um.find(vi[i]);
            if(umi!=um.end()){
                umi->second.push_back(vt[i]->val);
            }else{
                vc={vt[i]->val};
                um.emplace( vi[i], vc);
            }            
            
            if(vt[i]->left){
                vs.push_back(vt[i]->left);
                vj.push_back(vi[i]-1);
            }
            if(vt[i]->right){
                vs.push_back(vt[i]->right);
                vj.push_back(vi[i]+1);
            }
        }
        return ;
    }
    
/*    void dfs(unordered_map<int, vector<int>>& um, TreeNode* tr, int lv){
        if(tr->left)    dfs( um, tr->left, lv-1);
        if(tr->right)   dfs( um, tr->right, lv+1);
        unordered_map<int, vector<int>>::iterator umi=um.find(lv);
        if(umi!=um.end()){
            umi->second.push_back(tr->val);
        }else{
            vector<int> vc={tr->val};
            um.emplace( lv, vc);
        }        
        return ;
    }*/
};
