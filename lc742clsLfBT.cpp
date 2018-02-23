
/*
Leetcode 742. Closest Leaf in a Binary Tree

Companies 
Amazon, databricks
Related Topics 
Tree 

Next challenges: Unique Binary Search Trees II, 
Serialize and Deserialize Binary Tree, Two Sum IV - Input is a BST

Test Cases:
[1,2,3,4,null,null,null,5,null,6]
2
[1,3,2]
1
[1]
1
[1,2,3,null,null,4,5,6,null,null,7,8,9,10]
3
[1,2,3,null,null,4,5,6,null,null,7,8,9,10]
4

Runtime: 17 ms
Sorry. We do not have enough accepted submissions to show runtime distribution chart.

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
    int findClosestLeaf(TreeNode* root, int k) {
        // There exists some node in the given binary tree for which node.val == k.

        // DFS, pre-order&in-order traversal; find k; O(n) time & O(h) space 
        TreeNode* tr;
        vector<TreeNode*> vt={root};// path pf parents of k
        vector<int> vi={2};
        if(root->val!=k){
            while(!vt.empty()){
                if(1<vi.back()){//==2
                    tr=vt.back();
                    vi.back()-=1;   
                    if(tr->left){
                        vt.push_back(tr->left);
                        vi.push_back(2);                    
                        if(vt.back()->val==k)   break;
                    }
                }else if(0<vi.back()){//==1
                    tr=vt.back();
                    vi.back()-=1;
                    if(tr->right){
                        vt.push_back(tr->right);
                        vi.push_back(2);
                        if(vt.back()->val==k)   break;
                    }                    
                }else{//==0
                    vt.pop_back();
                    vi.pop_back();
                }
            }
        }
        
        // BFS, find closest leaf; O(n) time&space 
        pair<int,int> mn=closeLeaf(vt.back()), ds;// distance, leaf value
        for(int i=0; i<vt.size()-1; i++){
            if(vt[i]->left==vt[i+1]&&vt[i]->right!=NULL){
                ds=closeLeaf(vt[i]->right);
                if(ds.first+vt.size()-i-1<mn.first) mn=make_pair(ds.first+vt.size()-i-1,ds.second);
            }else if(vt[i]->right==vt[i+1]&&vt[i]->left!=NULL){
                ds=closeLeaf(vt[i]->left);
                if(ds.first+vt.size()-i-1<mn.first) mn=make_pair(ds.first+vt.size()-i-1,ds.second);
            }
            //cout<<vt[i]->val<<":"<<mn.first<<","<<mn.second<<endl;
        }
        
        return mn.second;
    }
   
protected:    
    pair<int,int> closeLeaf(TreeNode* tr){
        int len=0;
        vector<TreeNode*> vc={tr}, vd;
        while(!vc.empty()){
            vd.clear();
            for(int i=0; i<vc.size(); i++){
                if(vc[i]->left){
                    vd.push_back(vc[i]->left);
                    if(vc[i]->right)    vd.push_back(vc[i]->right);
                }else{
                    if(vc[i]->right)    vd.push_back(vc[i]->right);
                    else    return make_pair(len, vc[i]->val);
                }
            }
            len++;

            if(vd.empty())  return make_pair(-1,-1);// won't happen
            vc.clear();
            for(int i=0; i<vd.size(); i++){
                if(vd[i]->left){
                    vc.push_back(vd[i]->left);
                    if(vd[i]->right)    vc.push_back(vd[i]->right);
                }else{
                    if(vd[i]->right)    vc.push_back(vd[i]->right);
                    else    return make_pair(len, vd[i]->val);
                }
            }
            len++;
        }
        return make_pair(-1,-1);// won't happen
    }
};