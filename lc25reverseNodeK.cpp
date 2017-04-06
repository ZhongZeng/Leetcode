

/*
Leetcode # 25. Reverse Nodes in k-Group
You are here! 
Your runtime beats 92.62% of cpp submissions. 19 ms
Your runtime beats 48.43% of cpp submissions. 23 ms

Testcases:
[1,2,3,4,5,6,7,8,9,10,11,12,13]
4

[1,2,3,4,5,6,7,8,9,10,11,12]
[1,2,3,4,5,6,7,8,9,10,11]
[1,2,3,4]
[1,2,3]
[1,2]
[1]
[]
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        if(!(head->next)) return head;
        ListNode * node=head->next, * ltail, * ttail=head, * nexte, * laste=head, * headc;
        // node, the last tail, this head, the next element, the last element, returned head
        int count=0;
        /* the fist row */
        while(++count!=k){
            // cout<<"test1"<<endl;
            // cout<<node->val<<endl;
            if(node->next){
                nexte=node->next;
                node->next=laste;
                laste=node;
                node=nexte;
            }else{
                if(count==k-1){
                    /* k nodes in the 1st row */
                    head->next=NULL;
                    node->next=laste;
                    return node;
                }else{
                    /* [0,k) nodes in the 1st row 
                    re-reverse the last row */ 
                    nexte=laste;
                    laste=node;
                    node=nexte;
                    while(count--!=0){
                        //cout<<node->val<<endl;
                        nexte=node->next;
                        node->next=laste;
                        laste=node;
                        node=nexte;
                    }
                    return head;
                }
            }
        }
        headc=laste;// the return value
        ltail=head;
        
        /* til last rows */
        ttail=node;
        int j =0;
        while(node->next){
            // cout<<"test2"<<endl;
            count=0;
            ttail=node;
            nexte=node->next;// move node forward 1 node
            laste=node;
            node=nexte;
            while(++count!=k){
                if(node->next){ // node->next!=NULL
                    // cout<<node->val<<endl;
                    nexte=node->next;
                    node->next=laste;
                    laste=node;
                    node=nexte;
                }else{  // node->next==NULL
                    if(count==k-1){
                        /* k nodes in the last row*/
                        node->next=laste;
                        ltail->next=node;
                        ttail->next=NULL;
                        return headc;
                    }else{
                        /* [2,k) nodes in the last row
                        re-reverse the last row */ 
                        nexte=laste;
                        laste=node;
                        node=nexte;
                        while(--count!=0){
                            // cout<<node->val<<endl;
                            nexte=node->next;
                            node->next=laste;
                            laste=node;
                            node=nexte;
                        }
                        ltail->next=node;
                        return headc;
                    }
                }
            }
			ltail->next=laste;
			ltail=ttail;
        }
        /* one node in the last row */
        ltail->next=node;
        // cout<<"one node in the last row"<<endl;
        return headc;
    }
    
};

