/*
987. Vertical Order Traversal of a Binary Tree

Related Topics:	Hash Table, Tree 

Test Cases:
[3,9,20,null,null,15,7]
[1,2,3,4,5,6,7]
[0,1,null,null,2,6,3,null,null,null,4,null,5]
[0,5,1,9,null,2,null,null,null,null,3,4,8,6,null,null,null,7]
[0,8,1,null,null,3,2,null,4,5,null,null,7,6]
[]

Runtime: 0 ms
Memory Usage: 868.4 KB

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int mn=0, mx=0;
        unordered_map<int,vector<pair<int,int>>> um;// X, Y, val 
        dfs( um, root, 0, 0);
        
        for( auto umi=um.begin(); umi!=um.end(); umi++){
            if(umi->first<mn)   mn=umi->first;
            if(mx<umi->first)   mx=umi->first;
        }
        vector<int> vc;
        vector<vector<int>> vv(mx-mn+1,vc);
        
        for( auto umi=um.begin(); umi!=um.end(); umi++){
            sort( umi->second.begin(), umi->second.end(), comp );
            for( auto e:umi->second)    vv[umi->first-mn].push_back(e.second);// -mn is crucial 
        }
        
        return vv;
    }

protected:
    static bool comp(pair<int,int> p1, pair<int,int> p2){// sorted base on X then Y then value 
        if(p1.first<p2.first)   return false;
        else if(p2.first<p1.first)  return true;
        else    return p1.second<p2.second;
    }
    
    void dfs(unordered_map<int,vector<pair<int,int>>>& um, TreeNode * nd, int x, int y){
        if(!nd) return ;
        
        auto umi=um.find(x);
        if(umi!=um.end()){
            umi->second.push_back({make_pair(y,nd->val)});
        }else{
            vector<pair<int,int>> vc;
            vc.push_back(make_pair(y,nd->val));
            um.emplace(x,vc);
        }
        
        dfs( um, nd->left, x-1, y-1);
        dfs( um, nd->right, x+1, y-1);
        
        return ;
    }
};