
/*
Leetcode 148. Sort List

Related Topics 
Linked List, Sort 
Similar Questions 
Merge Two Sorted Lists, Sort Colors, Insertion Sort List

Next challenges: Insert Interval, 
Convert Sorted List to Binary Search Tree, Reorganize String

Test Cases:
[1,6,2,5,7,3,4]
[]

Runtime: 61 ms
Your runtime beats 18.80 % of cpp submissions.

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
    ListNode* sortList(ListNode* head) {
        // merge sort; note add/deletion/ time complexity of list differs from vector
        if(!head)   return head;
        
        int len=0;
        ListNode * st=head; 
        while(st){
            len++;
            st=st->next;
        }
        st=mergeSort(head, len);
        head=st;
        for(int i=0; i<len-1; i++)    st=st->next;
        st->next=NULL;
        
        return head;
    }
    
    ListNode* mergeSort(ListNode* ls, int len){
        if(len<2)   return ls;
        ListNode * lt=ls;
        int mid=len>>1; 
        for(int i=0; i<mid; i++)    lt=lt->next;
        ls=mergeSort(ls, mid);
        lt=mergeSort(lt, len-mid);
        return mergeList(ls, mid, lt, len-mid);;
    }
    
    ListNode* mergeList(ListNode* ls, int len1, ListNode* lt, int len2){
        // merge sorted list 
        ListNode * rt, * st;// node to return, last node 
        int i=0, j=0;
        if(ls->val<lt->val){
            rt=ls;
            ls=ls->next;
            i++;
        }else{
            rt=lt;
            lt=lt->next;
            j++;
        }
        st=rt;
        
        while( i<len1&&j<len2 ){
            //cout<<st->val<<" ";
            if(ls->val<lt->val){
                st->next=ls;
                st=ls;
                ls=ls->next;
                i++;
            }else{
                st->next=lt;
                st=lt;
                lt=lt->next;
                j++;
            }
        }
        //cout<<endl;
        
        if(j==len2) st->next=ls;
        else    st->next=lt;
        
        return rt;// what left beyond the end doesn't matter
    }
};
