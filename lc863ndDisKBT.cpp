
/*			

Leetcode 863. All Nodes Distance K in Binary Tree

Test Cases: 
[3,5,1,6,2,0,8,null,null,7,4]
5
2
[0,null,1,null,2,null,3]
1
2
[0,2,1,null,null,3]
3
3
[0,1,null,null,2,null,3,null,4]
3
0

Runtime: 7 ms

Next challenges: Number Complement, Zuma Game, Bold Words in String

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // BFS & DFS; Each node in the tree has unique values 0 <= node.val <= 100.
        TreeNode * tr=root;
        bool b=false;
        vector<int> rt;
        vector<TreeNode*> vn;
        if(!root)   return rt;
        
        dfs( tr, target, vn);// post-order DFS to find target's ancestors
        //for(auto e:vn)  cout<<e->val<<" ";  cout<<endl;
        
        bfs( vn.back(), rt, K);
        
        for( int i=vn.size()-2; -1<i; i--){
            if(vn.size()-1-i<K){// vn.size()-i-1<=K
                if(vn[i]->left){
                    if(vn[i]->left->val!=vn[i+1]->val)  bfs( vn[i]->left, rt, K-(vn.size()-i) );
                    else    bfs( vn[i]->right, rt, K-(vn.size()-i) );
                }// else no need for BFS 
            }else if(vn.size()-1-i==K){// vn.size()-1-i==K
                rt.push_back(vn[i]->val);
                break;
            }else{
                break;
            }
        }
        
        return rt;
    }
    
    void bfs( TreeNode * tr, vector<int>& rt, int d){// BFS 
        if(!tr) return;
        
        vector<TreeNode*> vn, un;
        vn.push_back(tr);
        
        while(!vn.empty()){
            if(d!=0){
                un.clear();
                for( int i=0; i<vn.size(); i++){
                    if(vn[i]->left) un.push_back(vn[i]->left);
                    if(vn[i]->right)    un.push_back(vn[i]->right);
                }
                vn=un;
                d--;
            }else{
                for( int i=0; i<vn.size(); i++) rt.push_back(vn[i]->val);
                return ;
            }
        }
        
        return ;
    }
    
    bool dfs(TreeNode * tr, TreeNode* target, vector<TreeNode*>& vn){// post-order DFS
        if(!tr) return false;
        
        vn.push_back(tr);
        
        if(tr->val==target->val)    return true;
        
        if(dfs( tr->left, target, vn))   return true;
        if(dfs( tr->right, target, vn))  return true;
        
        vn.pop_back();
        
        return false;
    }
};
