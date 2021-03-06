
/*
947. Most Stones Removed with Same Row or Column

Related Topics: Depth-first Search ,Union Find 

Test Cases:
[[0,1],[1,0],[1,1]]
[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
[[0,0],[0,2],[1,1],[2,0],[2,2]]
[[0,0]]

Runtime: 20 ms, faster than 93.33% of C++ online submissions for Most Stones Removed with Same Row or Column.

A group of stones is defined as all stones that can be connected by rows or columns, which means each stone in the group is at least on the same row or column with another stone in the group. A group is essentially a connected graph. All stones in the same group are removable except the last one. Thus, the totoal number of stones remaining is the number of groups.
We can do a DFS on each stone to count the total number groups. DFS is faster than Union Find, because the union step may take more than O(1) time.

Time Complexity O(V+E):
V: # stones/vertex; E: # edges b/t stones 

*/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // DFS, O(n^2) (actually O(V+E)) time; Union Find is slower w.r.t time 
		// stones connected by row&column are connected graph, removable except 1
		int gp=0;
		vector<int> vc(stones.size(),-1);
		unordered_map<int,vector<int>> row, col;// row,col as key
		
		for( int i=0; i<stones.size(); i++){// build graph 
			emplaceUm( stones[i][0], i, row);
			emplaceUm( stones[i][1], i, col);
		}
		
		for( int i=0; i<stones.size(); i++)
			if(vc[i]==-1)   dfs( i, ++gp, vc, stones, row, col);
		
		return stones.size()-gp;
    }
	
protected:
	void emplaceUm( int key, int i, unordered_map<int,vector<int>>& um){
		unordered_map<int,vector<int>>::iterator umi=um.find(key);
		if(umi!=um.end())   umi->second.push_back(i);
        else    um.emplace(key,vector<int>{i});
		return ;
	}
	
	void dfs( int i, int gp, vector<int>& vc, vector<vector<int>>& stones, 
		unordered_map<int,vector<int>>& row, unordered_map<int,vector<int>>& col){
		if(vc[i]==-1)	vc[i]=gp;
		else	return ;
		
		unordered_map<int,vector<int>>::iterator umi=row.find(stones[i][0]);
		for( int j=0; j<umi->second.size(); j++)
            dfs( umi->second[j],gp,vc,stones,row,col);
		
		umi=col.find(stones[i][1]);
		for( int j=0; j<umi->second.size(); j++)
            dfs( umi->second[j],gp,vc,stones,row,col);
		
		return ;
	}
};