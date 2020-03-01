/*
1367. Linked List in Binary Tree

Companies	SoundHound
Related Topics: Linked List, Dynamic Programming, Tree 

Test Cases:
[4,2,8]
[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
[1,4,2,6]
[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
[1,4,2,6,8]
[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]

Runtime: 28 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 23.9 MB
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        // O(n+m) time; pre-order DFS 
        vector<int> vc;
        for( ListNode* ln=head; ln; ln=ln->next)    vc.push_back(ln->val);
        
        return dfs( vc, 0, root);
    }
    
protected:
    bool dfs( vector<int> & vc, int loc, TreeNode * tn){
        if(loc==vc.size())  return true;
        if(!tn) return false;
        
        if(loc==0
           &&(dfs(vc,0,tn->left)||dfs(vc,0,tn->right)))
            return true;
        
        if(vc[loc]==tn->val&&
           (dfs(vc, loc+1, tn->left)||dfs(vc, loc+1, tn->right)))
            return true;
        
        return false;
    }
};