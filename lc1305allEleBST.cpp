/*
1305. All Elements in Two Binary Search Trees

Companies	Amazon
Related Topics	Sort, Tree 

Test Cases:
[2,1,4]
[1,0,3]
[0,-10,10]
[5,1,7,0,2]
[]
[5,1,7,0,2]
[0,-10,10]
[]

Runtime: 268 ms	Your runtime beats 85.82 % of cpp submissions.
Memory Usage: 57.1 MB
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // O(m+n) time, O(h1+h2) space; In-order DFS by Iteration, Two-Pointer 
        vector<int> vc;
        vector<TreeNode*> vr1, vr2;
        findSmallest( root1, vr1);
        findSmallest( root2, vr2);
        
        while((!vr1.empty())||(!vr2.empty())){
            if(vr2.empty()) findNext( vr1, vc);
            else if(vr1.empty())    findNext( vr2, vc);
            else if(vr1.back()->val<vr2.back()->val)    findNext( vr1, vc);
            else findNext( vr2, vc);
        }
        
        return vc;
    }
    
protected:
    void findSmallest( TreeNode * root, vector<TreeNode*> & vr){
        for( TreeNode * tr=root; tr!=NULL; tr=tr->left) vr.push_back(tr);
        return ;
    }
    
    void findNext( vector<TreeNode*> & vr, vector<int> & vc){
        vc.push_back(vr.back()->val);
        
        TreeNode * tr=vr.back()->right;
        vr.pop_back();
        findSmallest( tr, vr);
        return ;
    }
};