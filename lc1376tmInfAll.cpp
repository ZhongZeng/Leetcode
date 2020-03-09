/*
1376. Time Needed to Inform All Employees

Company	Google
Related Topics	Depth-first Search
Similar Questions	
Maximum Depth of Binary Tree, Binary Tree Maximum Path Sum

Test Cases:
1
0
[-1]
[0]
6
2
[2,2,-1,2,2,2]
[0,0,1,0,0,0]
4
2
[3,3,-1,2]
[0,0,162,914]

Runtime: 432 ms
Memory Usage: 22 MB

https://leetcode.com/problems/time-needed-to-inform-all-employees/discuss/532759/c-on-time-no-dfs-or-bfs-traverse-from-each-node-towards-root
*/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // O(n) Time, b/c each edge will only be visited once. This is a tree, so there are n-1 edges.
        // traverse towards root; post-order DFS, O(n) time; BFS, Dijkstra
        int max=0;
        vector<int> time_to_root(manager.size(), -1);// time to inform i from root
        
        for( int i=0; i<manager.size(); i++){
            int time=0;
            for( int j=manager[i]; j!=-1; j=manager[j]){
                time+=informTime[j];
                if(-1<time_to_root[j]){
                    time+=time_to_root[j];
                    break;
                }
            }
            time_to_root[i]=time;
            max=time<max?max:time;
        }
        
        return max;
    }
};