/*
You are here! 
Your runtime beats 23.29% of cpp submissions
LeetCode # 206. Reverse Linked List
*/

using nsmespace std;

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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode * temp1=NULL, * temp2;
        while(head->next){
            temp2 = head->next;
            head->next = temp1;
            temp1 = head;
            head = temp2;
        }
        head->next = temp1;
        return head;
    }
};