
/*
Leetcode 559. Maximum Depth of N-ary Tree

Related Topics 
Tree, Depth-first Search, Breadth-first Search 
Similar Questions 
Maximum Depth of Binary Tree

Test Case:
{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}

Next challenges: Freedom Trail, Remove Boxes, Number of Distinct Islands

Runtime: 40 ms
Your runtime beats 94.47 % of cpp submissions.

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
    int maxDepth(Node* root) {
        // BFS
        if(!root)   return 0;
        int d=0;
        vector<Node*> vn={root}, vm;
        
        while( !vn.empty() ){
            d++;
            for( int i=0; i<vn.size(); i++){
                for( int j=0; j<vn[i]->children.size(); j++){
                    vm.push_back(vn[i]->children[j]);
                }
            }
            vn=vm;
            vm.clear();
        }
        
        return d;
    }
};
