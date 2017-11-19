

/*

Leetcode 725. Split Linked List in Parts

Related Topics 
Linked List 
Similar Questions 
Rotate List, Odd Even Linked List 

Test Cases:
[1,2,3,4]
5

[1,2,3,4,5]
2

Next challenges: Design Phone Directory, Add Two Numbers II

Runtime: 9 ms
You are here! 
Your runtime beats 35.14 % of cpp submissions.

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode * ls=root, *nxt;
        int len=0, r, d, i=-1;
        vector<ListNode*> vc;
        while( ls!=NULL ){
            ls=ls->next;
            len++;
        }
        
        d=len/k;
        r=len-d*k;
        
        ls=root;
        while( ++i!=r ){
            vc.push_back(ls);
            for(int j=0; j!=d; j++){
                //cout<<ls->val;
                ls=ls->next;
            }               
            nxt=ls->next;
            ls->next=NULL;
            ls=nxt;
        }
        
        if( d!=0 ){
            while( i++!=k ){
                vc.push_back(ls);
                for(int j=1; j!=d; j++){
                    //cout<<ls->val;
                    ls=ls->next;
                }               
                nxt=ls->next;
                ls->next=NULL;
                ls=nxt;
            }           
        }else{
            while( i++!=k ){
                vc.push_back(NULL);
            }            
        }
            
        return vc;
    }
};
