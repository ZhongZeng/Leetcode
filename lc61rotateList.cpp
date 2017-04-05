
/*
Leetcode # 61. Rotate List
You are here! 
Your runtime beats 82.23% of cpp submissions 9 ms
Your runtime beats 48.88% of cpp submissions. 12 ms
Your runtime beats 17.43% of cpp submissions. 16 ms
Your runtime beats 3.88% of cpp submissions. 22 ms
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode * nodef=head, * nodes=head, * headc;
        int len=0, st; //length, step
        
        /* find the length of the list*/
        while(nodef->next && nodef->next->next){
            nodes=nodes->next;
            nodef=nodef->next->next;
            len++;
        }
        
        /* bind the last and first nodes*/
        st=len*2;
        if(nodef->next) {// an even # of nodes
            nodef=nodef->next;
            len++;
            st++;
        }
        nodef->next=head;
        
        /* cut at the last nth node*/
        k=k%(st+1);
        if(len<k){
            while(k<st--) head=head->next;
            headc=head->next;
            head->next=NULL;
        }else{
            while(k<len--) nodes=nodes->next;
            headc=nodes->next;
            nodes->next=NULL;
        }
        
        return headc;
    }
};
