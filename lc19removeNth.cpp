

/*
Leetcode # 19. Remove Nth Node From End of List
You are here! 
Your runtime beats 1.66% of cpp submissions 16 ms
Your runtime beats 10.02% of cpp submissions.
Your runtime beats 21.80% of cpp submissions. 9 ms
Your runtime beats 65.45% of cpp submissions. 6 ms

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* this is inspired by others' solution*/
        ListNode * node1=head, * node2=head;
        int cn=0;
        while( cn++!=n){
            node1=node1->next;
        }
        
        if(!node1) return head->next;
        while(node1->next){
            node1=node1->next;
            node2=node2->next;
        }
        node2->next=node2->next->next;
        return head;
    }
};
