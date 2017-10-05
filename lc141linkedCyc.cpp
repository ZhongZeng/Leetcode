

/*
Leetcode 141. Linked List Cycle

Related Topics 
Linked List, Two Pointers 
Similar Questions 
Linked List Cycle II 

Runtime: 12 ms
You are here! 
Your runtime beats 29.36 % of cpp submissions.


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
    bool hasCycle(ListNode *head) {
        if(head==NULL)  return false;
        ListNode * ls1=head, * ls2=head;
        while( ls2->next != NULL && ls2->next->next!=NULL ){
            ls1 = ls1->next;
            ls2 = ls2->next->next;              
            if( ls1==ls2 ){
                return true;
            }                      
        }
        return false; 
    }
};
