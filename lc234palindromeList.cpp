
/*
Leetcode # 234. Palindrome Linked List
You are here! 
Your runtime beats 50.64% of cpp submissions.
Two Pointer method is used in this solution. 
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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode * node1 = head, * node2 = head; 
        while(node2->next){
            if(node2->next->next){
                node1 = node1->next;
                node2 = node2->next->next;
                // cout<< node1->val<< " "<< node2->val<< endl;
            }else{
                break;
            }
        }
        
        node2 = inverseList(node1->next);
        node1 = head;
        
        while(node2){
            if(node1->val == node2->val){
                node1 = node1->next;
                node2 = node2->next;
            }else{
                return false;
            }
        }
        return true;
        
    }

protected:    
    ListNode* inverseList(ListNode* l){
        ListNode* temp1 = NULL, * temp2;
        while(l){
            temp2 = l->next;
            l->next = temp1;
            temp1 = l;
            l = temp2;
        }
        return temp1;
    }
};

