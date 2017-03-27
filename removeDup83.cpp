
/*
Leetcode 83. Remove Duplicates from Sorted List
You are here! 
Your runtime beats 56.86% of cpp submissions
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* head0= head;

        while( head->next!=NULL){
            if(head->val == head->next->val){
                if(head->next->next!=NULL){
                    head->next = head->next->next;
                }else{
                    head->next = NULL;
                    return head0;
                }
            }else{
                head = head->next;
            }
        }
        
        return head0;
        
    }
};

