
/*
Leetcode 382. Linked List Random Node

Companies  
Google, Apple, LinkedIn, Baidu, Adobe 
Related Topics 
Reservoir Sampling 
Similar Questions 
Random Pick Index 

Test Case:
["Solution","getRandom"]
[[[1,2,3]],[]]

Next challenges: Maximum Sum of 3 Non-Overlapping Subarrays, 
To Lower Case, Number of Subarrays with Bounded Maximum

Runtime: 32 ms
Your runtime beats 10.54 % of cpp submissions.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        for( ListNode* ln=head; ln; ln=ln->next)    vl.push_back(ln);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int rd=rand()%vl.size();
        return vl[rd]->val;
    }
    
    vector<ListNode*> vl;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */