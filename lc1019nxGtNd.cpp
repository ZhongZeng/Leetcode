/*
1019. Next Greater Node In Linked List

Companies	Microsoft
Related Topics	Linkedin List, Stack 

Test Cases:
[2,1,5]
[2,7,4,3,5]
[1,7,5,1,9,2,5,1]

Runtime: 220 ms
Memory Usage: 27.4 MB

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
    vector<int> nextLargerNodes(ListNode* head) {
        // O(n) time, stack
        vector<int> vl, po, rt;
        int i=0;
        for( ListNode * ln=head; ln!=NULL; ln=ln->next, i++){
            rt.push_back(0);
            while(0<vl.size()&&vl.back()<ln->val){
                rt[po.back()]=ln->val;
                vl.pop_back();
                po.pop_back();
            }
            vl.push_back(ln->val);
            po.push_back(i);
        }
        return rt;
    }
};