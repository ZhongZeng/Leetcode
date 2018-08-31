
/*
Leetcode 708. Insert into a Cyclic Sorted List

Companies   
Facebook 
Related Topics 
Linked List 
Similar Questions 
Insertion Sort List

Test Cases:
null
1
{"$id":"1","next":{"$id":"2","next":{"$id":"3","next":{"$ref":"1"},"val":3},"val":3},"val":3}
0
{"$id":"1","next":{"$id":"2","next":{"$id":"3","next":{"$ref":"1"},"val":1},"val":4},"val":3}
2

Runtime: 44 ms
Your runtime beats 13.22 % of cpp submissions.

Next challenges: Convert Sorted List to Binary Search Tree, Design Linked List

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node * rt=new Node;
        rt->val=insertVal;
        
        if(head==NULL){// corner case mentioned in problem description 
            rt->next=rt;
            return rt;
        }
        
        Node * nd=head, * nx=head->next;
		do{
			if(nd->val<nx->val){
				if(nd->val<=insertVal&&insertVal<=nx->val)	break;
			}else if(nx->val<nd->val){
				if(nd->val<=insertVal||insertVal<=nx->val)	break;
			}
            nd=nx;
            nx=nx->next;
		}while(nd!=head);// good for case of all same values 
		
        rt->next=nx;
        nd->next=rt;
        
		return head;
    }
};
