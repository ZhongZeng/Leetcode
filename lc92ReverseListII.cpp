

/*
92. Reverse Linked List II
You are here! 
Your runtime beats 19.28% of cpp submissions.
*/

using namespace std;

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        /* m==1 */
        if(m==1){
            int cn= 1;
            ListNode * temp1=head, * node=temp1->next, * temp2;
            while(node){
                if(n == cn++) break; // be careful about the position of operator ++
                temp2 = node->next;
                node->next = temp1;
                temp1 = node;
                node = temp2;
            }
            head->next = node;
            return temp1;
        }
        
        /* 1<m */
        int cn= 1;
        ListNode * node = head, * temp1, * temp2, * st, * stm;
        while(node){
            if(m == ++cn) break; // be careful about the position of operator ++
            node = node->next;
        }
        st = node; // start
        stm = node->next;
        // cout <<"st"<< st->val << endl;
        
        cn--;
        temp1 = stm;
        node = temp1->next;
        while(node){
            if(n == ++cn) break; // be careful about the position of operator ++
            temp2 = node->next;
            node->next = temp1;
            temp1 = node;
            node = temp2;
        }
        // cout <<"node"<< node->val << endl;
        
        st->next = temp1;
        stm->next = node;
        
        return head;
    }
};
