

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
[0]
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
// Runtime: 28 ms, faster than 98.10% of C++ online submissions for Add Two Numbers II.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// O(n) time, O(1) space except output; modify output 
        int len1=listLength(l1), len2=listLength(l2), i, ad;
        if(len2<len1)   return addTwoNumbers(l2, l1);
		ListNode * rt=new ListNode(0), * ll;
		
		for( i=0, ll=rt; i<len2-len1; i++){// len1<=len2 
			ListNode * ln0=new ListNode(l2->val);
            l2=l2->next;
			ll->next=ln0;
			ll=ln0;
        }
		for( ; i<len2; i++){// add values from 2 lists 
			ListNode * ln0=new ListNode(l1->val+l2->val);
            l1=l1->next;
            l2=l2->next;
			ll->next=ln0;
			ll=ln0;
		}
		//for(ll=rt;ll;ll=ll->next)   cout<<ll->val<<" "; cout<<endl;
        
		rt=reverseList(rt);// addtion due to >9 values 
		for( ll=rt, i=0, ad=0; ll; ll=ll->next){
			ll->val=ll->val+ad;
			if(9<ll->val){
				ll->val-=10;
				ad=1;
			}else{
				ad=0;
			}
		}
		rt=reverseList(rt);
		
		return rt->val!=0?rt:(rt->next?rt->next:rt);
    }
	
protected:
	ListNode * reverseList(ListNode * ln){
		ListNode * ll=NULL, * lt;
		for( ; ln; ll=ln, ln=lt){
			lt=ln->next;
			ln->next=ll;
		}
		return ll;
	}

	int listLength(ListNode* ln){
		int len=0;
		for( ; ln; ln=ln->next)	len++;
		return len;
	}
};

// Runtime: 28 ms, faster than 98.10% of C++ online submissions for Add Two Numbers II. 2018/12/23
// Runtime: 62 ms	Your runtime beats 15.54 % of cpp submissions. a year ago
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
