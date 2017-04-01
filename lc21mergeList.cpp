

/*
LeetCode # 21. Merge Two Sorted Lists
You are here! 
Your runtime beats 23.75% of cpp submissions.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head, *temp;
        if( l1==NULL ) {
            if( l2==NULL ) {
                return NULL;
            }else{
                return l2;   
            }
        }else{
            if( l2==NULL ){
                return l1;
            }
        }
        
        if( l1->val < l2->val) {
            head = l1;
        }else{
            head = l2;
        }
        
        while(l1!=NULL && l2!=NULL ){
            // cout<< l1->val <<" "<<l2->val <<endl;
            if( l1->val < l2->val) {
                l1 = findNext(l1, l2);
                temp = l1->next;
                l1->next = l2;
                l1 = temp;
            }else{
                l2 = findNext(l2, l1);
                temp = l2->next;
                l2->next = l1;
                l2 = temp;
            }
        }
        
        
        return head;
    }
    
protected:    
    ListNode* findNext(ListNode* l1, ListNode* l2){ 
        // assuming l1->val < l2-val w/t losing generality
        while( l1->next && l1->next->val <= l2->val){
            l1= l1->next;
        }
        return l1;
    }
};
