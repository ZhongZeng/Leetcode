/*
1557. Minimum Number of Vertices to Reach All Nodes
Medium

Companies	Google
Related Topics	Graph

Test Cases:
6
[[0,1],[0,2],[2,5],[3,4],[4,2]]
5
[[0,1],[2,1],[3,1],[1,4],[2,4]]

Runtime: 960 ms, faster than 33.33% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
Memory Usage: 94.4 MB, less than 83.33% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
Next challenges: Path With Maximum Minimum Value, Sort Integers by The Power Value,
Parallel Courses II
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // All vertices w/t incoming edge, O(V+E) time; DAG; Topological Sort
        vector<int> vertices(n,0), reach_from;
        for( int i=0; i<edges.size(); i++)
            vertices[edges[i][1]]=1;
        for( int i=0; i<vertices.size(); i++)
            if(vertices[i]==0)  reach_from.push_back(i);
        return reach_from;
    }
};