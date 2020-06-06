/*
1135. Connecting Cities With Minimum Cost

Medium
Companies	Uber
Related Topics	Union Find, Graph

Runtime: 548 ms, faster than 20.54% of C++ online submissions for Connecting Cities With Minimum Cost.
Memory Usage: 70 MB, less than 9.60% of C++ online submissions for Connecting Cities With Minimum Cost.
Next challenges: Minimize Malware Spread, Smallest String With Swaps,
Sort Integers by The Power Value
*/

struct lessThan{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.second>p2.second;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        // O(n+m*log(m)) time; Greedy, BFS, Dijkstra; connections[i][0] != connections[i][1]
        if(N<1) return 0;
        int sum=0, tot=0;
        vector<int> connected(N,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,lessThan> pq;
        unordered_map<int,unordered_map<int,int>> costs;// city A, B, cost
        for( int i=0; i<connections.size(); i++){
            addConnection( connections[i][0]-1, connections[i][1]-1, connections[i][2], costs);
            addConnection( connections[i][1]-1, connections[i][0]-1, connections[i][2], costs);
        }
        
        for( pq.push(make_pair(0,0)); 0<pq.size()&&tot<N; ){
            int city=pq.top().first, cost=pq.top().second;
            pq.pop();
            if(connected[city]==1)  continue;
            connected[city]=1;
            sum+=cost;
            tot++;
            
            unordered_map<int,unordered_map<int,int>>::iterator it=costs.find(city);
            if(it==costs.end()) continue;
            for( unordered_map<int,int>::iterator jt=it->second.begin(); jt!=it->second.end(); jt++){
                if(connected[jt->first]==0) pq.push(make_pair(jt->first,jt->second));// reduce runtime
            }
        }
        
        return tot==N?sum:-1;
    }
    
protected:
    void addConnection( int a, int b, int cost, 
        unordered_map<int,unordered_map<int,int>> & costs){
        if(costs.find(a)!=costs.end()){
            if(costs[a][b]!=NULL)    costs[a][b]=costs[a][b]<cost?costs[a][b]:cost;
            else    costs[a][b]=cost;
        }else{
            costs[a]={{b, cost}};
        }
        return ;
    }
};