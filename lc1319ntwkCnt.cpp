/*
1319. Number of Operations to Make Network Connected

Companies	Akuna Capital
Related Topics	Depth-first Search, Breadth-first Search, Union Find 

Test Cases:
4
[[0,1],[0,2],[1,2]]
6
[[0,1],[0,2],[0,3],[1,2],[1,3]]
6
[[0,1],[0,2],[0,3],[1,2]]
5
[[0,1],[0,2],[3,4],[2,3]]

Runtime: 232 ms, faster than 6.95% of C++ online submissions for Number of Operations to Make Network Connected.
Memory Usage: 62.1 MB, less than 100.00% of C++ online submissions for Number of Operations to Make Network Connected.

Lonely Pixel II
Flip Binary Tree To Match Preorder Traversal
Lexicographically Smallest Equivalent String
*/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Union Find, O(n) space, O(n*n) time, count clusters & redundant connections
		// DFS||BFS, O(n) time 
        int rc=connections.size()-(n-1), cl=countClusters(n, connections);// redudant connectinos, # clusters 
        return -1<rc?cl-1:-1;
    }
    
protected:
    int countClusters( int & n, vector<vector<int>>& connections){
        // Union Find 
        unordered_set<int> us;
        vector<int> vc;
        for( int i=0; i<n; i++) vc.push_back(i);
        
        for( int i=0; i<connections.size(); i++){
            vector<int> vd=findAncestors( vc, connections[i][0]), ve=findAncestors(vc, connections[i][1]);
            // union&path compression 
            for(int j=0; j<vd.size(); j++)  vc[vd[j]]=vd.back();
            for(int j=0; j<ve.size(); j++)  vc[ve[j]]=vd.back();
        }
        
        // set each node to its ancestor 
        for( int i=0; i<vc.size(); i++){
            vector<int> vd=findAncestors( vc, i);
            for(int j=0; j<vd.size(); j++)  vc[vd[j]]=vc[vd.back()];
        }
        
        for( int i=0; i<vc.size(); i++) us.emplace(vc[i]);
        
        return us.size();
    }
    
    vector<int> findAncestors( vector<int> & vc, int b){
        vector<int> vd={b};
        while(vc[vd.back()]!=vd.back()) vd.push_back(vc[vd.back()]);
        return vd;
    }
};