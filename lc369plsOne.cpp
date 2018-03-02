
/*
Leetcode 369. Plus One Linked List

Companies 
Google 
Related Topics 
Linked List 
Similar Questions 
Plus One

Next challenges: Convert Sorted List to Binary Search Tree, 
Copy List with Random Pointer, Design Phone Directory

Test Cases:
[1,2,3]
[9,9,9]

Runtime: 4 ms
Your runtime beats 4.78 % of cpp submissions.

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
    ListNode* plusOne(ListNode* head) {
        if(!head)   return head;
        ListNode* rt=reverseList(head), * st=rt;
        bool one=true;
        while(one&&rt->next!=NULL){
            if(8<rt->val){//rt->val==9
                rt->val=0;
                rt=rt->next;
            }else{
                rt->val+=1;
                one=false;
            }
        }
        
        if(one){
            if(8<rt->val){//rt->val==9
                rt->val=0;
                ListNode * n=new ListNode(1);
                rt->next=n;
            }else{
                rt->val+=1;
            }
        }
        
        rt=reverseList(st);
        
        return rt;
    }
    
    ListNode* reverseList(ListNode * head){
        ListNode* ls=NULL, * t;
        
        while(head!=NULL){
            t=head->next;
            head->next=ls;
            ls=head;
            head=t;
        }
        
        return ls;
    }
};