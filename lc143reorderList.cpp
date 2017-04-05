

/*
Leetcode 143. Reorder List
You are here! 
Your runtime beats 15.88% of cpp submissions. 79 ms
Your runtime beats 27.73% of cpp submissions. 66 ms
Your runtime beats 55.70% of cpp submissions. 56 ms
*/

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
    void reorderList(ListNode* head) {
        if(!head) return;
        if(!head->next) return;
        if(!head->next->next) return;
        
        /*find the # (n+1)/2 point*/
        ListNode * nodes=head, * nodef=head, * templ, * tempn;
        while(nodef->next && nodef->next->next){
            nodes=nodes->next;
            nodef=nodef->next->next;
        }
        
        /*reverse the 2nd of the list*/
        if(nodef->next) nodes=nodes->next;// an even # of nodes
        // an odd # of nodes
            
        templ=nodes;
        nodes=nodes->next;
        templ->next=NULL;
        
        while(nodes->next){
            tempn=nodes->next;// the next node
            nodes->next=templ;
            templ=nodes;
            nodes=tempn;
        }
        nodes->next=templ;
        
        /*merger two halfs of the list*/
        while(head->next && nodes->next){
            templ=head->next;
            tempn=nodes->next;
            head->next=nodes;
            nodes->next=templ;
            head=templ;
            nodes=tempn;
        }
        return;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main(){
	ListNode l1(1), l2(2);
	l1.next = &l2;
	cout<<l1.val<<endl;
	cout<<l1.next->val<<endl;
	// true || false
	if( l1.next || l1.next->next)	cout<<"true1"<<endl;
	// true || NULL->next->next
	if( l1.next || l2.next->next->next)	cout<<"true2"<<endl;
	// false && NULL->next->next
	if( l2.next && l2.next->next->next)	cout<<"true3"<<endl;
	cout<<"end"<<endl;
	
	return 0;
}

