
/*

Leetcode 86. Partition List

Related Topics 
Linked List, Two Pointers 

Next challenges: Add Two Numbers II, K-diff Pairs in an Array, Candy Crush

Test Cases:
[1,3,2]
3
[1,2,3]
2
[2,1,3]
2
[2,3,1]
2
[3,3,1,2,4]
3

Runtime: 6 ms
You are here! 
Your runtime beats 22.97 % of cpp submissions

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
    ListNode* partition(ListNode* head, int x) {
        ListNode * ls1=head, * ls2=head, * prev, * ls3, * ls4; 
        while( ls1!=NULL && !(ls1->val<x) )   ls1=ls1->next;         
        while( ls2!=NULL && ls2->val<x )  ls2=ls2->next;        
        if( !( ls1!=NULL && ls2!=NULL ) )   return head;     
        
        //cout<<ls1->val<<endl<<ls2->val<<endl;

        ls3 = ls1;
        ls4 = ls2;
        
        while( head!=NULL ){
            if( head->val<x ){
                if( head!=ls3 ){
                    ls1->next = head;
                    ls1 = head; 
                }
            }else{
                if( head!=ls4 ){
                    ls2->next = head;
                    ls2 = head; 
                }                                
            }
            head = head->next; 
        }      
        ls1->next = ls4;  
        ls2->next = NULL;
        
        return ls3;
    }
};
