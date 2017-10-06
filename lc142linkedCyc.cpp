
/*
Leetcode 142. Linked List Cycle II

Related Topics 
Linked List Two Pointers 
Similar Questions 
Linked List Cycle Find the Duplicate Number 

Next challenges: Find the Duplicate Number

Runtime: 9 ms
You are here! 
Your runtime beats 39.88 % of cpp submissions.

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
    ListNode *detectCycle(ListNode *head) {
		// ls1_steps + cycle_len * rep = ls1_steps * 2
		// len_start + more = ls1_step
		// len_start = cycle_len * rep - more
        if(head==NULL)  return NULL;
        ListNode * ls1=head, * ls2=head;
        while( ls2->next!=NULL && ls2->next->next!=NULL ){
            ls1 = ls1->next;
            ls2 = ls2->next->next;
            if( ls1==ls2 ){
                ls1 = head;
                while(ls1!=ls2){
                    ls1=ls1->next;
                    ls2=ls2->next;
                }
                return ls1;                
            }            
        }                
        return NULL; 
    }
};

