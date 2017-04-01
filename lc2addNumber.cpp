

/*
Leetcode #2. Add Two Numbers
You are here! 
Your runtime beats 72.74% of cpp submissions.
Your runtime beats 88.19% of cpp submissions.
The code may look a little messy, but it's fast, 
because lots are hard coded.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1){
            if(!l2){
                return l1; // l1 != NULL && l2==NULL     
            }
        }else{
            return l2; // l1==NULL
        }
        
        // both are not NULL
        ListNode* head = l1;
        int addone =0;
        while(l1->next){
            // cout<<l1->val<<" "<<l2->val<<endl;
            l1->val += l2->val + addone;
            if(l1->val < 10){
                addone = 0;
            }else{
                addone = 1;
                l1->val -= 10;
            }
            
            if(l2->next){// l1->next!=NULL && l2->next!=NULL
                l1 = l1-> next;
                l2 = l2-> next;
            }else{// l1->next!=NULL && l2->next==NULL
                l1 = l1->next;
                addDigit(l1, addone);
                return head;
            }
        }// l1->next!=NULL && l2->next!=NULL
        
        if(l2->next){// l1->next==NULL && l2->next!=NULL
            // cout<<"test2"<<endl;
            addone = addDigit(l1, l2, addone);
            l1->next = l2->next;
            l1 = l1->next;
            addDigit(l1, addone);
            return head;
        }else{// l1->next==NULL && l2->next==NULL
            lastDigit(l1, l2, addone);
            return head;
        }
        
    }
    
protected:
    int addDigit(ListNode* l1, ListNode* l2, int addone){
        l1->val += l2->val + addone;
        if(l1->val < 10){
            addone = 0;
        }else{
            addone = 1;
            l1->val -= 10;
        }
        return addone;
    }
    
    void addDigit(ListNode* l1, int addone){
        while(l1->next){
            //cout<<l1->val<<endl;
            l1->val += addone;
            if(l1->val < 10){
                return;
            }else{
                addone = 1;
                l1->val -= 10;
            }
            l1 = l1->next;
        }
        lastDigit(l1, addone);
        return;
    }
    
    void lastDigit(ListNode* l1, ListNode* l2, int addone){
        l1->val += l2->val + addone;
        if(9<l1->val){
            l1->val -= 10;
            ListNode* lt = new ListNode(1);
            // this is important. Use new, not ListNode lt(1);
            l1->next = lt;
        }
        return;
    }
    
    void lastDigit(ListNode* l1, int addone){
        l1->val += addone;
        if(9<l1->val){
            l1->val -= 10;
            ListNode* lt = new ListNode(1);
            l1->next = lt;
        }
        return;
    }
};

