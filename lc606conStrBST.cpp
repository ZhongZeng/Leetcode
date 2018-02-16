
/*
Leetcode 606. Construct String from Binary Tree

Related Topics 
String, Tree 
Similar Questions 
Construct Binary Tree from String, Find Duplicate Subtrees

Next challenges: Construct Binary Tree from String, Find Duplicate Subtrees

Test Cases:
[1,2,3,4]
[]
[1,2,3,null,4]
[1,null,2,null,3,null,4,null,5,null,6]

Runtime: 16 ms
Your runtime beats 42.00 % of cpp submissions.

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
    string tree2str(TreeNode* t) {
        // pre-order traversal, DFS 
        if(!t)  return "";
        string s;
        vector<TreeNode*> vt;
        vector<int> vv;
        
        s.append(to_string(t->val));
        if(t->left){
            if(t->right){
                vt.push_back(t->right);
                vt.push_back(t->left);
                vv.push_back(1);
                vv.push_back(1);
            }else{
                vt.push_back(t->left);
                vv.push_back(1);                        
            }
        }else{
            if(t->right){
                s.append("()");
                vt.push_back(t->right);
                vv.push_back(1);                        
            }                    
        }        
        
        while(!vt.empty()){
            if(vv.back()!=0){
                t=vt.back();
                vv.back()=0;
                s.push_back('(');
                s.append(to_string(t->val));
                if(t->left){
                    if(t->right){
                        vt.push_back(t->right);
                        vt.push_back(t->left);
                        vv.push_back(1);
                        vv.push_back(1);
                    }else{
                        vt.push_back(t->left);
                        vv.push_back(1);
                    }
                }else{
                    if(t->right){
                        s.append("()");
                        vt.push_back(t->right);
                        vv.push_back(1);                        
                    }                    
                }
            }else{
                vt.pop_back();
                vv.pop_back();
                s.push_back(')');
            }
        }
        
        return s;
    }
};
