
/*
Leetcode # 24. Swap Nodes in Pairs
You are here! 
Your runtime beats 34.52% of cpp submissions.
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!(head->next)) return head;
        if(!(head->next->next)){
            head->next->next=head;
            ListNode * headc = head->next;
            head->next=NULL;
            return headc;
        }
        
        ListNode  * temp1=head, * tempn, * headc=head->next, * node1=headc->next;
        temp1->next->next = temp1;
        head->next = NULL;
        
        while( node1->next){
            //cout << "test"<< endl;
            if(node1->next->next) {
                temp1->next = node1->next; 
                temp1 = node1; // update temp1
                tempn = node1->next->next; // store the next node1
                node1->next->next = node1; 
                node1 = tempn; // update node1
            }else{// an even # of nodes
                temp1->next = node1->next;
                node1->next->next = node1;
                node1->next = NULL;
                return headc;
            } 
        }
        temp1->next = node1;// an odd # of nodes
        return headc;
    }
};