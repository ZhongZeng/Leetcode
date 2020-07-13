/*
1514. Path with Maximum Probability

Medium
Companies	Google
Related Topics Graph

Test Cases:
3
[[0,1],[1,2],[0,2]]
[0.5,0.5,0.2]
0
2
3
[[0,1],[1,2],[0,2]]
[0.5,0.5,0.3]
0
2
3
[[0,1]]
[0.5]
0
2

Runtime: 848 ms
Memory Usage: 79.6 MB
*/

struct comp{
    bool operator()(pair<double,int> pr1, pair<double,int> pr2){
        return pr1.first<pr2.first;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Dijkstra, Priority Queue, Greedy; succProdb[i] in [0,1] 
        priority_queue<pair<double,int>,vector<pair<double,int>>,comp> prob;
        unordered_map<int,unordered_map<int,double>> edge_map;
        vector<int> visited(n,0);
        
        for( int i=0; i<edges.size(); i++){
            addEdge( edges[i][0], edges[i][1], succProb[i], edge_map);
            addEdge( edges[i][1], edges[i][0], succProb[i], edge_map);
        }
        
        for( prob.push(make_pair(1, start)); !prob.empty(); ){
            double p=prob.top().first;
            int node=prob.top().second;
            if(node==end)   return p;
            prob.pop();
            
            if(visited[node]==1)    continue;
            visited[node]=1;
            
            unordered_map<int,unordered_map<int,double>>::iterator it=edge_map.find(node);
            if(it==edge_map.end())  continue;
            for( unordered_map<int,double>::iterator jt=it->second.begin(); jt!=it->second.end(); jt++){
                if(visited[jt->first]==0){
                    prob.push(make_pair(jt->second*p, jt->first));
                }
            }
        }
        
        return 0;
    }
    
protected:
    void addEdge( int a, int b, double & p, unordered_map<int,unordered_map<int,double>> & edge_map){
        unordered_map<int,unordered_map<int,double>>::iterator it=edge_map.find(a);
        if(it!=edge_map.end())  it->second[b]=p;
        else    edge_map[a][b]=p;
        return ;
    }
};