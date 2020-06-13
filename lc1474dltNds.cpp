/*
1474. Delete N Nodes After M Nodes of a Linked List

Easy
Companies	Microsoft
Related Topics	Linked List

Test Cases:
[1,2,3,4,5,6,7,8,9,10,11,12,13]
2
3

Runtime: 48 ms, faster than 37.21% of C++ online submissions for Delete N Nodes After M Nodes of a Linked List.
Memory Usage: 14 MB, less than 100.00% of C++ online submissions for Delete N Nodes After M Nodes of a Linked List.
Next challenges: Remove Zero Sum Consecutive Nodes from Linked List

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        for( ListNode * nd=head; nd; ){
            for( int i=0; i<m-1&&nd!=NULL; i++, nd=nd->next){}
            if(!nd) break;
            ListNode * nx=nd;
            for( int i=0; i<n+1&&nx!=NULL; i++, nx=nx->next){}
            nd->next=nx;
            nd=nx;
        }
        return head;
    }
};