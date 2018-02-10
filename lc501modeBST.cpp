

/*
Leetcode 501. Find Mode in Binary Search Tree

Related Topics 
Tree 
Similar Questions 
Validate Binary Search Tree

Next challenges: Count Univalue Subtrees, 
Serialize and Deserialize Binary Tree, Boundary of Binary Tree

Test Cases:
[]
[1,null,2,2]
[6,2,8,0,4,7,9,null,null,2,6]
[2147483647]

Runtime: 15 ms
Your runtime beats 70.87 % of cpp submissions.

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
    vector<int> findMode(TreeNode* root) {
        // hash_table and O(n) space is trivial
		// in-order traversal, DFS 
        vector<int> vc;
        if(!root)   return vc;
        int mc=0, cc=0, t=root->val;// cc=1, t=root->val+1; is WRONG 
        
        findMode( root, vc, mc, cc, t);
        if(mc<cc){
            vc.clear();
            vc.push_back(t);
            mc=cc;
        }else if(mc==cc){
            vc.push_back(t);
        }
        
        return vc;
    }
    
protected:    
    void findMode(TreeNode* tr, vector<int>& vc, int& mc, int& cc, int& t){
        
        if(tr->left)    findMode(tr->left, vc, mc, cc, t);

        if(t==tr->val){
            cc++;
        }else{
            if(mc<cc){
                vc.clear();
                vc.push_back(t);
                mc=cc;
            }else if(mc==cc){
                vc.push_back(t);
            }
            t=tr->val;
            cc=1;            
        }

        if(tr->right)   findMode(tr->right, vc, mc, cc, t);
        return ;
    }
    
};


/*
// Wrong Answer 17/25 [6,2,8,0,4,7,9,null,null,2,6]
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        // hash_table and O(n) space is trivial
        vector<int> vc;
        if(!root)   return vc;
        int mc=0, cc=0;
        
        findMode(root, vc, mc, cc);
        
        return vc;
    }

protected:    
    void findMode(TreeNode* tr, vector<int>& vc, int& mc, int& cc){
        cc++;
        if(tr->right&&tr->right->val==tr->val){
            findMode(tr->right, vc, mc, cc);
            if(tr->left&&tr->left->val==tr->val){
                findMode(tr->left, vc, mc, cc);
            }else{
                if(tr->left){
                    cc=0;
                    findMode(tr->left, vc, mc, cc);
                }
            }
        }else{
            if(tr->left&&tr->left->val==tr->val){
                findMode(tr->left, vc, mc, cc);
            }else{
                updateMx(tr, vc, mc, cc);
                if(tr->left){
                    cc=0;
                    findMode(tr->left, vc, mc, cc);
                }
            }
            if(tr->right){
                cc=0;
                findMode(tr->right, vc, mc, cc);                
            }
        }
        
        return ;        
    }
    
    void updateMx(TreeNode* tr, vector<int>& vc, int& mc, int& cc){
        if(mc<cc){
            vc.clear();
            vc.push_back(tr->val);
            mc=cc;
        }else if(mc==cc){
            vc.push_back(tr->val);
        }
        return ;
    }
    
};
*/
