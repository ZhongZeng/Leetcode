/*
1627. Graph Connectivity With Threshold

Hard

Companies:	Trexquant
Related Topics:	Math, Union Find

Runtime: 552 ms
Memory Usage: 70.9 MB
*/

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        // Union Find; O(n*n+q) time 
        vector<bool> connected;
        vector<int> parents;
        for( int i=0; i<n; i++) parents.push_back(i);
        
        for( int i=threshold+1; i<=n; i++){
            vector<int> ancestors;
            for( int t=i; t<=n; t+=i)   ancestors.push_back(findAncestor(parents, t-1));
            for( int j=1; j<ancestors.size(); j++)
                parents[ancestors[j]]=parents[ancestors[0]];
        }
        
        for( int i=0; i<queries.size(); i++){
            connected.push_back(
                findAncestor(parents, queries[i][0]-1)==findAncestor(parents, queries[i][1]-1));
        }
        
        return connected;
    }
    
protected:
    int findAncestor( vector<int> & parents, int t){
        int a=t;
        while( parents[a]!=a )  a=parents[a];
        return a;
    }
};