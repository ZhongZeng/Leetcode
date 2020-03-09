/*
1377. Frog Position After T Seconds

Companies	Google
Related Topics	Depth-first Search 

Test Cases:
7
[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]
2
4
7
[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]
1
7
7
[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]
20
6
3
[[2,1],[3,2]]
1
2
1
[]
1
1

Runtime: 40 ms, faster than 22.22% of C++ online submissions for Frog Position After T Seconds.
Memory Usage: 13.9 MB, less than 100.00% of C++ online submissions for Frog Position After T Seconds.

Next challenges:
Number of Enclaves
Maximum Difference Between Node and Ancestor,
Sum of Nodes with Even-Valued Grandparent,
Show off your acceptance:

https://leetcode.com/problems/frog-position-after-t-seconds/discuss/532769/c-post-order-dfs
*/

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // tree: there is 1 and only 1 path b/t any 2 nodes; edges b/t 1 & target <= t 
        // possibility of not being on target a/t t seconds is NOT easy to solve 
        if(n<2) return 1;
        unordered_map<int,vector<int>> ed;
        vector<int> vt( n+1, 0);// 0-unvisited, 1-visited 
        
        for( int i=0; i< edges.size(); i++){
            recordEdge( ed, edges[i][0], edges[i][1]);
            recordEdge( ed, edges[i][1], edges[i][0]);
        }
        
        return dfs( 1, target, t, ed, vt);
    }
    
protected:
    void recordEdge( unordered_map<int,vector<int>> & ed, int a, int b){
        unordered_map<int,vector<int>>::iterator edi=ed.find(a);
        if(edi!=ed.end()){
            edi->second.push_back(b);
        }else{
            vector<int> vc={b};
            ed.emplace(a, vc);
        }
        return ;
    }
    
    double dfs( int current, int target, int t, unordered_map<int,vector<int>> & ed, vector<int> & vt){
        // current node, target node, remaining time, visited nodes
        // post-order DFS; return possibility from current to target w/ edges/steps <= t
        if(t==0) return current==target?1:0;
        
        unordered_map<int,vector<int>>::iterator edi=ed.find(current);
        int nodes=0;
        for( int i=0; i<edi->second.size(); i++){
            if(vt[edi->second[i]]==0)   nodes++;
        }
        
        // 1 of 2 following: unnecessary but speeds up algo 
        if(current==target) return nodes==0?1:0;
        if(nodes==0)    return current==target?1:0;
        
        // dfs 
        vt[current]=1;
        for( int i=0; i<edi->second.size(); i++){
            if(vt[edi->second[i]]==0){
                double p=dfs( edi->second[i], target, t-1, ed, vt);
                if(0<p) return p/nodes;
            }
        }
        vt[current]=0;
        
        return 0;
    }
};

/*
Runtime: 64 ms, faster than 22.22% of C++ online submissions for Frog Position After T Seconds.
Memory Usage: 14.1 MB, less than 100.00% of C++ online submissions for Frog Position After T Seconds.
Next challenges:
Redundant Connection II, Smallest String Starting From Leaf, Tree Diameter
*/
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // tree: there is 1 and only 1 path b/t any 2 nodes; edges b/t 1 & target <= t 
        // possibility of not being on target a/t t seconds is NOT easy to solve 
        if(n<2) return 1;
        unordered_map<int,vector<int>> ed;
        vector<int> vt( n+1, 0);// 0-unvisited, 1-visited 
        
        for( int i=0; i< edges.size(); i++){
            recordEdge( ed, edges[i][0], edges[i][1]);
            recordEdge( ed, edges[i][1], edges[i][0]);
        }
        
        return dfs( 1, target, t, ed, vt);
    }
    
protected:
    void recordEdge( unordered_map<int,vector<int>> & ed, int a, int b){
        unordered_map<int,vector<int>>::iterator edi=ed.find(a);
        if(edi!=ed.end()){
            edi->second.push_back(b);
        }else{
            vector<int> vc={b};
            ed.emplace(a, vc);
        }
        return ;
    }
    
    double dfs( int current, int target, int t, unordered_map<int,vector<int>> & ed, vector<int> & vt){
        // current node, target node, remaining time, edges, visited nodes
        // post-order DFS; return possibility from current to target w/ edges/steps <= t
        if(t==0) return current==target?1:0;
        
        unordered_map<int,vector<int>>::iterator edi=ed.find(current);
        int nodes=0;
        for( int i=0; i<edi->second.size(); i++){
            if(vt[edi->second[i]]==0)   nodes++;
        }
        
        // 1 of 2 following is unnecessary but speeds up algo; order switchable
        if(nodes==0)    return current==target?1:0;// stopped on node 
		if(current==target) return nodes==0?1:0;
        
        // dfs 
        vt[current]=1;
        for( int i=0; i<edi->second.size(); i++){
            if(vt[edi->second[i]]==0){
                double p=dfs( edi->second[i], target, t-1, ed, vt);
                if(0<p) return p/nodes;// at most 1 possible path 
            }
        }
        vt[current]=0;
        
        return 0;
    }
};

/*
Remove vector vt, which records visited node. 
b/c there is only 1 path b/t any 2 nodes, only need to compare next ndoe w/ previous node 
Runtime: 20 ms, faster than 94.75% of C++ online submissions for Frog Position After T Seconds.
Memory Usage: 13.3 MB, less than 100.00% of C++ online submissions for Frog Position After T Seconds.
Next challenges:
Redundant Connection II, Smallest String Starting From Leaf, Tree Diameter
*/
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // tree: there is 1 and only 1 path b/t any 2 nodes; edges b/t 1 & target <= t 
        // possibility of not being on target a/t t seconds is NOT easy to solve 
		// 0<n; edges can construct a valid tree 
		if(n<2)	return 1;// corner case: 1 node, no edges 
        unordered_map<int,vector<int>> ed;
        
        for( int i=0; i< edges.size(); i++){
            recordEdge( ed, edges[i][0], edges[i][1]);
            recordEdge( ed, edges[i][1], edges[i][0]);
        }
        
        return dfs( -1, 1, target, t, ed);
    }
    
protected:
    void recordEdge( unordered_map<int,vector<int>> & ed, int a, int b){
        unordered_map<int,vector<int>>::iterator edi=ed.find(a);
        if(edi!=ed.end())	edi->second.push_back(b);
        else	ed.emplace(a, vector<int> {b});
        return ;
    }
    
    double dfs( int previous, int current, int target, int t, unordered_map<int,vector<int>> & ed){
        // previous node, current node, target node, remaining time, edges 
        // post-order DFS; return possibility from current to target w/ edges/steps <= t
        if(t==0) return current==target?1:0;
        unordered_map<int,vector<int>>::iterator edi=ed.find(current); 
		int next_nodes=edi->second.size()-(previous!=-1?1:0);
        // 1 of 2 following (commented) is unnecessary but speeds up algo 
        if(next_nodes==0)	return current==target?1:0;// stop on leaf 
		if(current==target) return 0;// equivalent to return edi->second.size()==1?1:0; // pass target 
		
        // dfs 
        for( int i=0; i<edi->second.size(); i++){
            if(edi->second[i]!=previous){
                double p=dfs( current, edi->second[i], target, t-1, ed);
                if(0<p) return p/next_nodes;// at most 1 possible path 
            }
        }
        
        return 0;
    }
};