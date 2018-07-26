
/*

Leetcode 426. Convert Binary Search Tree to Sorted Doubly Linked List

Companies  
Facebook 
Related Topics 
Linked List, Divide and Conquer, Tree 
Similar Questions 
Binary Tree Inorder Traversal

Test Cases: 
{"$id":"1","val":4,"left":{"$id":"2","val":2,"left":{"$id":"4","val":1,"left":null,"right":null},"right":{"$id":"5","val":3,"left":null,"right":null}},"right":{"$id":"3","val":5,"left":null,"right":null}}
{"$id":"1","left":{"$id":"2","left":null,"right":{"$id":"3","left":{"$id":"4","left":{"$id":"5","left":{"$id":"6","left":{"$id":"7","left":null,"right":null,"val":-69},"right":{"$id":"8","left":{"$id":"9","left":{"$id":"10","left":null,"right":{"$id":"11","left":null,"right":null,"val":-36},"val":-39},"right":null,"val":-30},"right":null,"val":-20},"val":-60},"right":null,"val":-18},"right":{"$id":"12","left":{"$id":"13","left":{"$id":"14","left":null,"right":{"$id":"15","left":null,"right":{"$id":"16","left":null,"right":null,"val":14},"val":6},"val":-2},"right":{"$id":"17","left":{"$id":"18","left":null,"right":null,"val":40},"right":null,"val":42},"val":18},"right":{"$id":"19","left":{"$id":"20","left":null,"right":null,"val":54},"right":null,"val":55},"val":51},"val":-11},"right":{"$id":"21","left":null,"right":null,"val":68},"val":66},"val":-86},"right":{"$id":"22","left":null,"right":null,"val":98},"val":90}

Runtime: 16 ms
Your runtime beats 100.00 % of cpp submissions.

Runtime: 24 ms
Your runtime beats 3.27 % of cpp submissions.

Next challenges: Convert Sorted List to Binary Search Tree, 
Serialize and Deserialize BST, Encode N-ary Tree to Binary Tree

Next challenges: Unique Binary Search Trees II, The Skyline Problem, Find Duplicate Subtrees

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
		if(!root)	return root;
	
        vector<Node*> vn;
		dfs( root, vn);
		
		Node * bg=root, * ed=root;
		while(bg->left)	bg=bg->left;
		while(ed->right)ed=ed->right;
		
		bg->left=ed;
		ed->right=bg;
		
		return bg;
    }
	
	void dfs( Node * nd, vector<Node*>& vn){// in-order DFS 
		if(nd->left)	dfs( nd->left, vn);
		
		if(!vn.empty()){
			nd->left=vn.back();
			vn.back()->right=nd;
			vn.pop_back();
		}
		vn.push_back(nd);
		//cout<<nd->val<<" ";
		
		if(nd->right)	dfs( nd->right, vn);
		
		return ;
	}
};