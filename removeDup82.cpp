
/*
Leetcode 82. Remove Duplicates from Sorted List II
You are here! 
Your runtime beats 67.19% of cpp submissions.
Your runtime beats 22.70% of cpp submissions.
Your runtime beats 15.33% of cpp submissions.
*/

#include<vector>
#include<iostream>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next==NULL) return head;
        if(head->val == head->next->val) {
            do{
                head = head->next;
            }while( head->next && head->val==head->next->val);
            return deleteDuplicates(head->next);
        }

        ListNode* node = head, * temp;
        while( node->next->next != NULL){
            //cout<<node->val<<endl;
            if( node->next->val== node->next->next->val){
                temp = node;
                temp = node->next;
                while( temp->next!=NULL && temp->val== temp->next->val){
                    temp->next = temp->next->next;    
                }
                
                if( temp->next==NULL){
                    node->next = NULL;
                    return head;
                }else{
                    node->next = temp->next;
                }
            }else{
                node = node->next;
            }
        }
        
        return head;
    }
};