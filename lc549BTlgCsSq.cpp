
/*
Leetcode 549. Binary Tree Longest Consecutive Sequence II

Companies 
Google
Related Topics 
Tree 
Similar Questions 
Binary Tree Longest Consecutive Sequence

Next challenges: Recover Binary Search Tree, 
Largest BST Subtree, Construct Binary Tree from String

Test Cases:
[1,2,3,4]
[2,1,3]
[1,2,3,3,1]

Runtime: 21 ms
Your runtime beats 1.43 % of cpp submissions.
Runtime: 16 ms
Your runtime beats 9.05 % of cpp submissions.

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
    int longestConsecutive(TreeNode* root) {
        // DFS, post-order traversal; recursion 
        if(!root)   return 0;
        
        int mx=0;
        pair<int,int> pr=lgCn(root, mx, root->val);
        
        return mx;
    }
    
protected:    
    pair<int,int> lgCn(TreeNode* root, int& mx, int rv){
        // return longest ascending and descending sub sebsequence including the parent of this root
        if(!root)   return make_pair(1,1);
        pair<int,int> lp=lgCn(root->left, mx, root->val), rp=lgCn(root->right, mx, root->val);
        
        if(mx<lp.first+rp.second-1) mx=lp.first+rp.second-1;
        if(mx<rp.first+lp.second-1) mx=rp.first+lp.second-1;
        
        if(root->val==rv+1) return make_pair( 1+(lp.first<rp.first?rp.first:lp.first), 1);
        else if(root->val==rv-1)    return make_pair( 1, 1+(lp.second<rp.second?rp.second:lp.second));
        else    return make_pair(1,1);
    }
    
};


/*
// Wrong Answer 
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        // DFS, pre-order traversal
        if(!root)   return 0;
        int mx=1;
        lgCsc(root, 1, true, mx);
        return mx;
    }

protected:    
    void lgCsc(TreeNode* root, int len, bool asd, int& mx){// asd doesn't matter if(len==1)
        if(root->left){
            if(root->right){
                lgCsc(root, root->left, len, asd, mx);
                lgCsc(root, root->right, len, asd, mx);                
            }else{
                lgCsc(root, root->left, len, asd, mx);
            }
        }else{
            if(root->right) lgCsc(root, root->right, len, asd, mx);
            else    mx=mx<len?len:mx;
        }

        return ;
    }
    
    void lgCsc(TreeNode* root, TreeNode* chd, int len, bool asd, int& mx){        
        if(asd){
            if(chd->val==root->val+1){
                lgCsc(chd, len+1, asd, mx);
            }else{
                mx=mx<len?len:mx;
                if(chd->val==root->val-1)    lgCsc(chd, 2, false, mx);
                else    lgCsc(chd, 1, true, mx);
            }
        }else{
            if(chd->val==root->val-1){
                lgCsc(chd, len+1, asd, mx);
            }else{
                mx=mx<len?len:mx;
                if(chd->val==root->val+1)    lgCsc(chd, 2, true, mx);
                else    lgCsc(chd, 1, true, mx);
            }
        }
        //cout<<root->val<<","<<chd->val<<":"<<len<<endl;
        return ;
    }
};
*/