
/*
Leetcode 707. Design Linked List

Related Topics 
Linked List, Design 

Test Cases:
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
["MyLinkedList","get","addAtIndex","get","get","addAtIndex","get","get"]
[[],[0],[1,2],[0],[1],[0,1],[0],[1]]
["MyLinkedList","addAtHead","addAtIndex","addAtIndex","addAtTail","addAtHead","addAtIndex","addAtIndex","addAtIndex","addAtTail","addAtTail","deleteAtIndex"]
[[],[0],[1,9],[1,5],[7],[1],[5,8],[5,2],[3,0],[1],[0],[6]]
["MyLinkedList","addAtHead","addAtHead","deleteAtIndex","addAtIndex","addAtTail","addAtIndex","addAtTail","addAtHead","addAtHead","addAtHead","addAtTail","addAtTail","addAtHead","addAtTail","addAtTail","addAtHead","addAtTail","deleteAtIndex","addAtTail","addAtTail","get","addAtIndex","addAtHead","get","get","addAtHead","get","addAtIndex","addAtTail","addAtIndex","addAtHead","addAtHead","addAtHead","get","addAtHead","addAtIndex","addAtTail","addAtHead","addAtIndex","get","addAtTail","addAtTail","addAtIndex","addAtIndex","addAtHead","addAtHead","get","addAtTail","addAtIndex","addAtIndex","addAtHead","deleteAtIndex","addAtIndex","addAtHead","deleteAtIndex","addAtTail","deleteAtIndex","addAtTail","addAtHead","addAtTail","addAtTail","addAtHead","addAtTail","addAtIndex","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtTail","get","addAtIndex","addAtTail","addAtTail","addAtTail","deleteAtIndex","get","addAtHead","get","get","addAtTail","deleteAtIndex","addAtTail","addAtIndex","addAtHead","addAtIndex","addAtTail","get","addAtIndex","addAtIndex","addAtHead","addAtHead","get","get","get","addAtIndex","addAtHead","addAtIndex","addAtHead","addAtTail","addAtIndex","get"]
[[],[38],[45],[2],[1,24],[36],[3,72],[76],[7],[36],[34],[91],[69],[37],[38],[4],[66],[38],[14],[12],[32],[5],[7,5],[74],[7],[13],[11],[8],[10,9],[19],[3,76],[7],[37],[99],[10],[12],[1,20],[29],[42],[21,52],[11],[44],[47],[6,27],[31,85],[59],[57],[4],[99],[13,83],[10,34],[48],[9],[22,64],[69],[33],[5],[18],[87],[42],[1],[35],[31],[67],[36,46],[23],[64],[81],[29],[50],[23],[36,63],[8],[19],[98],[22],[28],[42],[24],[34],[32],[25],[53],[55,76],[38],[23,98],[27],[18],[44,27],[16,8],[70],[15],[9],[27],[59],[40,50],[15],[11,57],[80],[50],[23,37],[12]]

Next challenges: Design Log Storage System, Max Stack, Design HashSet

Runtime: 32 ms
Your runtime beats 26.92 % of cpp submissions.

*/

struct node{
	int val;
	node * next;
	node(){}
	node(int _val):val(_val),next(NULL){}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    // all 0-indexed 
    MyLinkedList() {// single-linked list 
        len=0;
		head=NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
		if(len<=index||index<0)	return -1;
		node * nd=head;
        //for( node * n=head; n!=NULL; n=n->next) cout<<n->val<<" ";  cout<<endl;
        for( int i=0; i<index; i++)	nd=nd->next;
		return nd->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
		node * nd=new node(val);
		nd->next=head;
		head=nd;
		
		len++;
		return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex( len, val);// NO len++; here! 

		return ;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {// insert value to be index-th (1-based) node 
        if(len<index||index<0)	return ;
		
        if(index==0){
			addAtHead(val);// len++ in addAtHead()
		}else{// 2<=index
            node * nd=head, * newNode=new node(val);
            
			for( int i=1; i<index; i++)	nd=nd->next;
			
			newNode->next=nd->next;
			nd->next=newNode;
			
			len++;
		}
		
		return ;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(len<=index||index<0)	return ;
		
		node * nd=head, * tn;
		if(index==0){
			head=head->next;
			delete nd;
		}else{// 1<=index
			for( int i=1; i<index; i++)	nd=nd->next;
			
            tn=nd->next;
			nd->next=nd->next->next;
			delete tn;
		}
        len--;
		
		return ;
    }
	
protected:
	int len;
	node * head; 
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
 