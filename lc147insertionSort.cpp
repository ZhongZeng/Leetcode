

/*
Leetcode # 147. Insertion Sort List
You are here! 
Your runtime beats 37.49% of cpp submissions. 53 ms
Your runtime beats 47.52% of cpp submissions. 52 ms
Your runtime beats 54.70% of cpp submissions. 49 ms

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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        if(!(head->next)) return head;
        ListNode * node = head->next, * tempn, * comp, * tempc, * headc = head;
        bool biggest = true;
        head->next = NULL;
        while(node){
            // cout << node->val << endl;
            tempn = node-> next; // store the next node
            node->next = NULL;
            
            if( node->val < headc->val){ // node->val < first comp
                node->next = headc;
                headc = node;
            }else{ // first comp <= node-val
                comp = headc;
                while( comp->next){// 
                    // cout << comp->next->val<<" comp->next->val" << endl;
                    if( node->val < comp->next->val ){
                        tempc = comp->next;
                        comp->next = node;
                        node->next = tempc;
                        biggest = false;
                        break;
                    }
                    comp = comp->next;
                }
                if( biggest){// the last comp < node->val
                    comp->next = node;
                    //node->next = NULL; 
                }else{
                    biggest = true;
                }
            }
                
            node = tempn;// move to the next node 
        }
        return headc;
        
    }
};

