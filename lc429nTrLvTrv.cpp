
/*
Leetcode 429. N-ary Tree Level Order Traversal

Related Topics 
Tree, Breadth-first Search 
Similar Questions 
Binary Tree Level Order Traversal, N-ary Tree Preorder Traversal, N-ary Tree Postorder Traversal

Test Case:
{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}

Next challenges: Find Duplicate Subtrees, Cut Off Trees for Golf Event, K-Similar Strings

Runtime: 44 ms
Your runtime beats 94.19 % of cpp submissions.

*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> rt;
        if(!root)   return rt;
        vector<Node*> vn, vm;
        vn.push_back(root);
        
        while(!vn.empty()){
            vector<int> vc;
            
            for( int i=0; i<vn.size(); i++){
                vc.push_back(vn[i]->val);
                for( int j=0; j<vn[i]->children.size(); j++)    vm.push_back(vn[i]->children[j]);
            }
            
            rt.push_back(vc);
            vn=vm;
            vm.clear();
        }
        
        return rt;
    }
};
