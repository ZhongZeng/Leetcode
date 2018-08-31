
/*
Leetcode 694. Number of Distinct Islands

Companies   
Amazon 
Related Topics 
Hash Table, Depth-first Search 
Similar Questions 
Number of IslandsNumber of Distinct Islands II

Test Case:
[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]

Runtime: 24 ms
Your runtime beats 82.12 % of cpp submissions.

Next challenges: Number of Distinct Islands II

*/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        // hash table, DFS, recursion, O(n) time&space 
		unordered_set<string> us;
		
		for( int i=0; i<grid.size(); i++){
			for( int j=0; j<grid[0].size(); j++){
				if(grid[i][j]==1)	path( i, j, grid, us);
			}
		}
		
		return us.size();
    }
	
	void path( int i, int j, vector<vector<int>>& grid, unordered_set<string>& us){
		// like cleaning robot 
		string str;
		
		dfs( i, j, grid, str);
		
		if(us.find(str)==us.end())	us.emplace(str);
		
		return ;
	}
	
	void dfs( int i, int j, vector<vector<int>>& grid, string& str){
        //cout<<i<<","<<j<<" ";
		grid[i][j]=2;
		
		if(0<i&&grid[i-1][j]==1){// up 
			str.push_back('u');
			dfs( i-1, j, grid, str);
			str.push_back('d');
		}

		if(i+1<grid.size()&&grid[i+1][j]==1){// down 
			str.push_back('d');
			dfs( i+1, j, grid, str);
			str.push_back('u');
		}

		if(0<j&&grid[i][j-1]==1){// left 
			str.push_back('l');
			dfs( i, j-1, grid, str);
			str.push_back('r');
		}		
		
		if(j+1<grid[0].size()&&grid[i][j+1]==1){// right 
			str.push_back('r');
			dfs( i, j+1, grid, str);
			str.push_back('l');
		}
		
		return ;
	}
};
