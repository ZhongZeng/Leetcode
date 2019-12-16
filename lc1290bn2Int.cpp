/*
1290. Convert Binary Number in a Linked List to Integer

Ranking of Weekly Contest 167  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (5)	Q3 (5)	Q4 (6)
2878 / 5453	zhongzeng 	8	1:23:12	 0:02:38	 1:23:12	

Companies	Roblox
Related Topics	Linked List, Bit Manipulation 

Test Cases:
[1,0,1]
[1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
[0,0]

Runtime: 4 ms	Your runtime beats 59.66 % of cpp submissions.
Memory Usage: 8.4 MB
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
    int getDecimalValue(ListNode* head) {
        int rt=0;
        for( ListNode * it=head; it!=NULL; it=it->next) rt=(rt<<1)+it->val;
        return rt;
    }
};