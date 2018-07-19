
/*
Leetcode 589. N-ary Tree Preorder Traversal

Related Topics 
Tree 
Similar Questions 
Binary Tree Preorder Traversal, N-ary Tree Level Order Traversal, N-ary Tree Postorder Traversal

Test Case:
{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}

Next challenges: N-ary Tree Level Order Traversal, N-ary Tree Postorder Traversal

Runtime: 52 ms
Your runtime beats 43.15 % of cpp submissions.

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> rt;
        
        dfs( root, rt);
        
        return rt;
    }
    
    void dfs( Node * tr, vector<int>& rt){// pre-order traversal DFS 
        if(tr)  rt.push_back(tr->val);
        else    return ;
        
        for( int i=0; i<tr->children.size(); i++){
            dfs( tr->children[i], rt);
        }
        
        return ;
    }
};
