

/*
Leetcode # 160. Intersection of Two Linked Lists
You are here! 
Your runtime beats 24.41% of cpp submissions.
Your runtime beats 41.25% of cpp submissions.
Your runtime beats 88.88% of cpp submissions.
"Simple C++ solution (5 lines)" is great. Prove its correctness.
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * node1 = headA, * node2 = headB;
        int diff=0;
        while(node1){
            if(node2){
                node1= node1->next;
                node2= node2->next;
            }else{
                while(node1){
                    node1 = node1->next;
                    diff++;
                }
            }
        }
        while(node2){
            node2 = node2->next;
            diff--;
        }
        
        node1 = headA;
        node2 = headB;
        int cn=0;
        if(diff < 1){
            while( cn-- != diff){
                node2 = node2->next;
            }
        }else{
            while( cn++ != diff){
                node1 = node1->next;
            }
        }
        while(node1){
            if(node1==node2) return node1;
            else{node1=node1->next; node2=node2->next;}
        }
        return NULL;
        
    }
};
