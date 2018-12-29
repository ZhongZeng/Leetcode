
/*
109. Convert Sorted List to Binary Search Tree

Related Topics: Linked List, Depth-first Search 
Similiar Questions: Convert Sorted Array to Binary Search Tree

Runtime: 20 ms	Your runtime beats 48.13 % of cpp submissions.

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
    TreeNode* sortedListToBST(ListNode* head) {
        // recursive in-order DFS, O(n) time, O(h) space, inspired from Discuss 
		int len=0;
		for(ListNode * tr=head; tr; tr=tr->next)	len++;
		
		return dfs(head,len);
    }
	
	TreeNode * dfs( ListNode * & ln, int len){// in-order DFS, pass by reference 
		if(len==0)	return NULL;
        
		TreeNode * l, * r, * p;
		l=dfs(ln,(len-1)/2);
		p=new TreeNode(ln->val);
		ln=ln->next;
		r=dfs(ln,len-1-(len-1)/2);
		
		p->left=l;
		p->right=r;
		
		return p;
	}
};
