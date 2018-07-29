
/*
876. Middle of the Linked List

Leetcode had similar problems 

Companies  
Walmart Labs 
Related Topics 
Linked List 

Test Cases:
[1,2,3,4,5]
[1,2,3,4,5,6]

Runtime: 0 ms

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
    ListNode* middleNode(ListNode* head) {// two pointer 
        if(!head)   return head;
        ListNode * l1=head, *l2=head;
        
        while(l2->next){
            l1=l1->next;
            l2=l2->next->next;
            if(!l2) return l1;
        }
        
        return l1;
    }
};
