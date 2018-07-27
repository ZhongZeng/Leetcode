

/*
Leetcode 430. Flatten a Multilevel Doubly Linked List

Companies  

Related Topics 
Linked List, Depth-first Search 
Similar Questions 
Flatten Binary Tree to Linked List

Test Case:
{"$id":"1","child":null,"next":{"$id":"2","child":null,"next":{"$id":"3","child":{"$id":"7","child":null,"next":{"$id":"8","child":{"$id":"11","child":null,"next":{"$id":"12","child":null,"next":null,"prev":{"$ref":"11"},"val":12},"prev":null,"val":11},"next":{"$id":"9","child":null,"next":{"$id":"10","child":null,"next":null,"prev":{"$ref":"9"},"val":10},"prev":{"$ref":"8"},"val":9},"prev":{"$ref":"7"},"val":8},"prev":null,"val":7},"next":{"$id":"4","child":null,"next":{"$id":"5","child":null,"next":{"$id":"6","child":null,"next":null,"prev":{"$ref":"5"},"val":6},"prev":{"$ref":"4"},"val":5},"prev":{"$ref":"3"},"val":4},"prev":{"$ref":"2"},"val":3},"prev":{"$ref":"1"},"val":2},"prev":null,"val":1}

Next challenges: Reconstruct ItineraryThe Maze IIIRobot Room Cleaner

Runtime: 24 ms
Your runtime beats 98.96 % of cpp submissions.

Runtime: 28 ms
Your runtime beats 9.38 % of cpp submissions.

*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {// this, child, next 
        // pre-order DFS
        if(!head)   return head;
        
        vector<Node*> vn;
        dfs( head, vn);
        
        return head;
    }
    
    void dfs(Node * nd, vector<Node*>& vn){// link to previous element 
        if(!vn.empty()){
            nd->prev=vn.back();
            vn.back()->next=nd;
            vn.pop_back();
        }
        
        vn.push_back(nd);
        //cout<<nd->val<<" ";
        
        Node * nx=nd->next;// to avoid infinite loop 
        
        if(nd->child)   dfs( nd->child, vn);
        nd->child=NULL;
        
        if(nx)  dfs( nx, vn);
        
        return ;
    }
};