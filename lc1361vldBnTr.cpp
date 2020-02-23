/*
1361. Validate Binary Tree Nodes

Companies	Facebook
Related Topcis	Graph 

Test Cases:
4
[1,-1,3,-1]
[2,-1,-1,-1]
4
[1,-1,3,-1]
[2,3,-1,-1]
2
[1,0]
[-1,-1]
6
[1,-1,-1,4,-1,-1]
[2,-1,-1,5,-1,-1]

Runtime: 52 ms
Memory Usage: 11.7 MB
*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // a valid tree: only 1 root node; fully connected; no circle (including no conflict parent-child)
        int root=-1, edges=0;
        vector<int> parent(leftChild.size(),-1);
        for( int i=0; i<leftChild.size(); i++){
            if(leftChild[i]!=-1){
                edges++;
                if(parent[leftChild[i]]!=-1)    return false;// a node can be only 1 parent's left child
                else    parent[leftChild[i]]=i;
            }
        }
        for( int i=0; i<rightChild.size(); i++){
            if(rightChild[i]!=-1){
                edges++;
                if(parent[rightChild[i]]!=-1&&parent[rightChild[i]]!=i) return false;// a node can have only 1 parent 
                else    parent[rightChild[i]]=i;
            }
        }
        // there is 1 and only 1 root 
        for( int i=0; i<parent.size(); i++){
            if(parent[i]==-1){
                if(root==-1)    root=i;
                else    return false;
            }
        }
        if(root==-1)    return false;
        
        return edges==leftChild.size()-1;// # edges == # nodes -1
    }
};