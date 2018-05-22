
/*
Leetcode 802. Find Eventual Safe States

Companies 
Google
Related Topics 
Depth-first Search, Graph 

Test Case:
[[1,2],[2,3],[5],[0],[5],[],[]]

Runtime: 156 ms
Your runtime beats 85.11 % of cpp submissions.

*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vt(graph.size(), 0), rt;
		// 0: unvisited; 1:started ; 2:eventual safe; 3:not eventual safe 
		// eventual safe==none of outgoing edge leads to a loop
		
		for(int i=0; i<graph.size(); i++)   dfs(i, vt, graph);
		
		for(int i=0; i<vt.size(); i++)	if(vt[i]!=3)	rt.push_back(i);
		
		return rt;
    }
	
	bool dfs(int i, vector<int>& vt, vector<vector<int>>& graph){
		if(vt[i]==1||vt[i]==3)	return false;//1:backward edge 
		else if(vt[i]==2)	return true;
		
		bool sf=true;
		vt[i]=1;
		for(int j=0; j<graph[i].size(); j++){
			if(!dfs(graph[i][j], vt, graph))	sf=false;
		}
		vt[i]=sf?2:3;
		
		return sf;
	}
};
