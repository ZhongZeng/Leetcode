

/*
Leetcode 445. Add Two Numbers II

Related Topics 
Linked List 
Similar Questions 
Add Two Numbers 

Test Cases:
[8,1,4,3]
[3,6,4]

[9,1,4,3]
[1,3,6,4]

Runtime: 62 ms
You are here! 
Your runtime beats 15.54 % of cpp submissions.

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
        // reverse the output list 
        int len1, len2;        
        len1=calLen(l1);
        len2=calLen(l2);
        
        return len1<len2 ? addNum( l1, l2, len1, len2):addNum( l2, l1, len2, len1);        
    }    

protected:
    int calLen( ListNode * l1 ){
        int len1=0;
        while( l1!=NULL ){
            l1=l1->next;
            len1++;            
        }
        return len1;
    }
    
    void reserveList( ListNode * l0 ){
        ListNode * prv=NULL, * nxt, *l=l0;
        while( l!=NULL ){
            //cout<<l->val<<endl;
            nxt = l->next;
            l->next = prv;
            prv = l;
            l = nxt;
        }
        return ;
    }
    
    ListNode * addNum(ListNode * l1, ListNode * l2, int len1, int len2){//len1<len2    
        //vector<ListNode> vc(len2, ListNode(0));
        ListNode * l;
        ListNode * lt = new ListNode(0), * l0=lt;
        
        for(int i=len1; i!=len2; i++){
            ListNode * l=new ListNode(l2->val);            
            lt->next=l;
            //cout<<i<<": "<<l2->val<<" "<<l->val<<endl;  
            lt=l;
            l2=l2->next;            
        }                
        
        for(int i=0; i!=len1; i++){              
            ListNode * l=new ListNode(l1->val+l2->val);              
            lt->next=l;
            //cout<<i<<": "<<l1->val<<" "<<l2->val<<" "<<l->val<<endl;
            lt=l;
            l1=l1->next;
            l2=l2->next;            
        }                
        lt->next=NULL;     
        l0=l0->next;        
        
        reserveList( l0 );        
        int dig=0;
        l=lt;
        while( l!=NULL ){
            if( dig!=0 )    l->val++;            
            if( 9<l->val ){
                l->val=l->val-10;
                dig=1;
            }else{
                dig=0;
            }
            l=l->next;
        }
                
        if(dig!=0){
            ListNode * ll=new ListNode(1);
            l0->next=ll;
            reserveList( lt);
            return ll;
        }else{
            reserveList( lt);
            return l0;
        }        
    }
};


/*
// Runtime: 48 ms
// You are here! 
// Your runtime beats 64.39 % of cpp submissions.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // This solution reserves input lists.
        // This solution is modified from 2. Add Two Numbers.
		l1=reserveList(l1);
		l2=reserveList(l2);
		
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
                head=reserveList(head);
                return head;
            }
        }// l1->next!=NULL && l2->next!=NULL
        
        if(l2->next){// l1->next==NULL && l2->next!=NULL
            // cout<<"test2"<<endl;
            addone = addDigit(l1, l2, addone);
            l1->next = l2->next;
            l1 = l1->next;
            addDigit(l1, addone);
            head=reserveList(head);
            return head;
        }else{// l1->next==NULL && l2->next==NULL
            lastDigit(l1, l2, addone);
            head=reserveList(head);
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

protected:
    ListNode * reserveList( ListNode * l0 ){
        ListNode * prv=NULL, * nxt, *l=l0;
        while( l!=NULL ){
            cout<<l->val<<" ";
            nxt = l->next;
            l->next = prv;
            prv = l;
            l = nxt;
        }
        //cout<<endl;
        return prv;
    }
	
};


*/
