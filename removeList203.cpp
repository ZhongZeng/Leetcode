
/*
Leetcode # 203. Remove Linked List Elements

You are here! 
Your runtime beats 22.90% of cpp submissions.
Your runtime beats 38.08% of cpp submissions.
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL){
            if(head->val==val) head = head->next;
            else break;
        }
        if(head==NULL) return head; //        
        for(ListNode* node=head; node->next != NULL; node = node->next){
            // cout << node->val << endl;
            while(node->next->val==val){
                if(node->next->next!=NULL) node->next = node->next->next;
                else {
                    node->next=NULL;
                    return head;
                }
            }
        }
        return head;   
    }
};

/*
Consider the following test cases:
[2,1,1,1,1,2]
1

[1]
1

[1,2,2,2,2,1]
1

*/
