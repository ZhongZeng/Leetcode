
/*
817. Linked List Components

Weekly Contest 80  
Rank: 744 / 2570

Companies 
Google
Related Topics 
Linked List 

Test Cases:
[0,1,2,3]
[0,1,3]
[0,1,2,3,4]
[0, 3, 1, 4]

Runtime: 37 ms

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
    int numComponents(ListNode* head, vector<int>& G) {
        bool b0=false;
        int sum=0;
        ListNode* ls=head;
        unordered_set<int> us;
        unordered_set<int>::iterator usi;
        
        for(vector<int>::iterator it=G.begin(); it!=G.end(); it++)  us.emplace(*it);
        
        while(ls!=NULL){
            if(us.find(ls->val)!=us.end()){
                if(!b0) sum++;
                b0=true;
            }else{
                b0=false;
            }
            ls=ls->next;
        }
        
        return sum;
    }
};