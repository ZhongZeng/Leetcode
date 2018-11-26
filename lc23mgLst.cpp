
/*
Leetcode 23. Merge k Sorted Lists

Companies   
Amazon, Facebook, Google, Microsoft, Apple, Uber, Alibaba, Tencent, Bloomberg, Paypal, Dropbox, Oracle 
Related Topics 
Linked List, Divide and Conquer, Heap 
Similar Questions 
Merge Two Sorted Lists, Ugly Number II

Test Cases:
[[1,4,5],[1,3,4],[2,6]]
[[1,4,5],[1,3,4],[2,6],[]]

Next challenges: Expression Add Operators, 
Minimum Number of Refueling Stops, Valid Permutations for DI Sequence

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Runtime: 16 ms	Your runtime beats 99.98 % of cpp submissions.
struct greaterThan{
	bool operator()(ListNode* ls1, ListNode* ls2){
		return ls1->val > ls2->val;
	}
};

class Solution {
public:
ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode * rt=NULL, * ls=new ListNode(0), * lt;
	priority_queue<ListNode*,vector<ListNode*>,greaterThan> hp;
	
	for( int i=0; i<lists.size(); i++){
		if(lists[i]!=NULL)	hp.push(lists[i]);
	}
	if(!hp.empty())	rt=hp.top();
	
	while(!hp.empty()){
		ls->next=hp.top();
		ls=hp.top();
		
		lt=hp.top()->next;
		hp.pop();
		if(lt!=NULL)	hp.push(lt);
	}
	
	return rt;
}
};

// Runtime: 16 ms	Your runtime beats 99.74 % of cpp submissions. 
// heap, linkedin list, similiar to merge k sorted array 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // O(n*log(k)) time 
        vector<ListNode*> vc;
        for( int i=0; i<lists.size(); i++){
            if(lists[i]!=NULL)  pushHp( vc, lists[i]);
        }
        if(vc.size()<1) return NULL;
        
        ListNode * head=vc[0], * ln=head, * lm;
        if(vc[0]->next!=NULL){
            lm=vc[0]->next;
            popHp(vc);
            pushHp(vc,lm);
        }else{
            popHp(vc);
        }
        
        while(!vc.empty()){
            ln->next=vc[0];
            ln=vc[0];
            if(vc[0]->next!=NULL){
                lm=vc[0]->next;
                popHp(vc);
                pushHp(vc,lm);
            }else{
                popHp(vc);
            }
        }
        
        return head;
    }
    
    void pushHp( vector<ListNode*>& vc, ListNode * nd){// min heap 
        int i=vc.size();
        vc.push_back(nd);
        
        while(0<i){
            if(vc[i]->val<vc[(i-1)/2]->val){
                nd=vc[i];
                vc[i]=vc[(i-1)/2];
                vc[(i-1)/2]=nd;
                i=(i-1)/2;
            }else{
                break;
            }
        }
        
        return ;
    }

    void popHp( vector<ListNode*>& vc){
        int i=0;
        ListNode * nd;
        vc[0]=vc.back();
        vc.pop_back();
        
        while(2*i+2<vc.size()){
            if(vc[2*i+2]->val<vc[i]->val&&vc[2*i+2]->val<vc[2*i+1]->val){
                nd=vc[i];
                vc[i]=vc[2*i+2];
                vc[2*i+2]=nd;
                i=2*i+2;
            }else if(vc[2*i+1]->val<vc[i]->val){
                nd=vc[i];
                vc[i]=vc[2*i+1];
                vc[2*i+1]=nd;
                i=2*i+1;
            }else{
                break;
            }
        }
        
        while(2*i+1<vc.size()&&vc[2*i+1]->val<vc[i]->val){
            nd=vc[i];
            vc[i]=vc[2*i+1];
            vc[2*i+1]=nd;
        }
        
        return ;
    }
};



/*
Leetcode 23. Merge k Sorted Lists

Related Topics 
Linked List, Divide and Conquer, Heap
Similar Questions 
Merge Two Sorted Lists, Ugly Number II

Next challenges: Ugly Number II

Test Cases:
[]
[[1,3,4],[2,4,7,10],[7,10,12]]
[[1],[0]]
[[-8,-7,-6,-3,-2,-2,0,3],[-10,-6,-4,-4,-4,-2,-1,4],[-10,-9,-8,-8,-6],[-10,0,4]]

Runtime: 29 ms
Your runtime beats 53.48 % of cpp submissions. 

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // heap sort, n*log(k) time, O(k) space 
		// inspired by tag heap
        vector<ListNode*> hp;
        ListNode * ls, * rt;
        
        for(int i=0; i!=lists.size(); i++){
            if(lists[i]!=NULL)  pushHp(hp, lists[i]);
        }
        
        if(hp.empty()){
            rt=NULL;
        }else{
            rt=hp[0];
            ls=hp[0];
            replaceHp(hp, ls->next);
        }
        
        while(!hp.empty()){// NULL pointer won't be pushed into heap
            ls->next=hp[0];
            ls=hp[0];
            replaceHp(hp, ls->next);
        }// the last element must point to NULL 
		
        return rt;
    }

    void replaceHp(vector<ListNode*> & hp, ListNode * ls){// replace the top/smallest element
        if(ls!=NULL){
            hp[0]=ls;
        }else{ // if NULL, pop 
            hp[0]=hp.back();
            hp.pop_back();
        }
        topDown(hp);
        return ;
    }    

	void topDown(vector<ListNode*> & hp){
		int i=0;
		ListNode * ls; 
		while(2*i+2<hp.size()){
            //cout<<hp[i]->val<<":"<<hp[i*2+1]->val<<":"<<hp[i*2+2]->val<<" ";
			if(hp[i*2+1]->val<hp[i]->val&&hp[i*2+1]->val<hp[i*2+2]->val){
				ls=hp[i*2+1];
				hp[i*2+1]=hp[i];
				hp[i]=ls;
                //cout<<hp[i]->val<<"one"<<hp[i*2+1]->val<<" ";
				i=2*i+1;
			}else if(hp[i*2+2]->val<hp[i]->val){
				ls=hp[i*2+2];
				hp[i*2+2]=hp[i];
				hp[i]=ls;
                //cout<<hp[i]->val<<"two"<<hp[i*2+2]->val<<" ";
				i=2*i+2;
			}else{
                //cout<<endl;
				return ;
			}
		}
		if(i*2+1<hp.size()&&hp[i*2+1]->val<hp[i]->val){
			ls=hp[i*2+1];
			hp[i*2+1]=hp[i];
			hp[i]=ls;
		}
        //cout<<endl;
		return ;
	}	
	
    void pushHp(vector<ListNode*> & hp, ListNode * ls){
        int i=hp.size();
		ListNode * ln; 
		hp.push_back(ls);
        while(-1<(i-1)/2&&hp[i]->val<hp[(i-1)/2]->val){ // can't use 0
            ln=hp[i];
            hp[i]=hp[(i-1)/2];
            hp[(i-1)/2]=ln;
            i=(i-1)/2;
		}
        return ;
    }	
};


