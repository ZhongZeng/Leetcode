
/*
Leetcode # 328. Odd Even Linked List
You are here! 
Your runtime beats 46.59% of cpp submissions.
Your runtime beats 15.90% of cpp submissions.
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode * lo = head, * le = head->next, * headE = head->next;
        while( le->next){
            // cout<<lo->val<<" "<<le->val<<endl;
            if(le->next->next){
                lo->next = le->next;
                le->next = le->next->next;
                lo = lo->next;
                le = le->next;
                // cout<<lo->val<<" "<<le->val<<" test 1"<<endl;
            }else{
                lo->next = le->next;
                le->next = NULL;
                lo->next->next = headE;
                return head;
            }
        }
        lo->next = headE; //lo->next = head->next; is WRONG, cuz head changed
        // cout<<"test2"<<endl;
        return head;
    }
};
