
/*
Leetcode 200. Number of Islands

Related Topics 
Depth-first SearchBreadth-first SearchUnion Find
Similar Questions 
Surrounded Regions, Walls and Gates, Number of Islands II, 
Number of Connected Components in an Undirected Graph, 
Number of Distinct IslandsMax Area of Island

Next challenges: Surrounded Regions, Walls and Gates, 
Number of Islands II, Number of Connected Components in an Undirected Graph, 
Number of Distinct IslandsMax Area of Island

Test Cases:
[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
[["1","0","0","1","1","1","0","1","1","0","0","0","0","0","0","0","0","0","0","0"],["1","0","0","1","1","0","0","1","0","0","0","1","0","1","0","1","0","0","1","0"],["0","0","0","1","1","1","1","0","1","0","1","1","0","0","0","0","1","0","1","0"]]
[["1","0","0","1","1","1","0","1","1","0","0","0","0","0","0","0","0","0","0","0"],["1","0","0","1","1","0","0","1","0","0","0","1","0","1","0","1","0","0","1","0"],["0","0","0","1","1","1","1","0","1","0","1","1","0","0","0","0","1","0","1","0"],["0","0","0","1","1","0","0","1","0","0","0","1","1","1","0","0","1","0","0","1"],["0","0","0","0","0","0","0","1","1","1","0","0","0","0","0","0","0","0","0","0"],["1","0","0","0","0","1","0","1","0","1","1","0","0","0","0","0","0","1","0","1"],["0","0","0","1","0","0","0","1","0","1","0","1","0","1","0","1","0","1","0","1"],["0","0","0","1","0","1","0","0","1","1","0","1","0","1","1","0","1","1","1","0"],["0","0","0","0","1","0","0","1","1","0","0","0","0","1","0","0","0","1","0","1"],["0","0","1","0","0","1","0","0","0","0","0","1","0","0","1","0","0","0","1","0"],["1","0","0","1","0","0","0","0","0","0","0","1","0","0","1","0","1","0","1","0"],["0","1","0","0","0","1","0","1","0","1","1","0","1","1","1","0","1","1","0","0"],["1","1","0","1","0","0","0","0","1","0","0","0","0","0","0","1","0","0","0","1"],["0","1","0","0","1","1","1","0","0","0","1","1","1","1","1","0","1","0","0","0"],["0","0","1","1","1","0","0","0","1","1","0","0","0","1","0","1","0","0","0","0"],["1","0","0","1","0","1","0","0","0","0","1","0","0","0","1","0","1","0","1","1"],["1","0","1","0","0","0","0","0","0","1","0","0","0","1","0","1","0","0","0","0"],["0","1","1","0","0","0","1","1","1","0","1","0","1","0","1","1","1","1","0","0"],["0","1","0","0","0","0","1","1","0","0","1","0","1","0","0","1","0","0","1","1"],["0","0","0","0","0","0","1","1","1","1","0","1","0","0","0","1","1","0","0","0"]]

Runtime: 12 ms
Your runtime beats 76.81 % of cpp submissions.

*/


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // DFS, O(m*n) time 
        // 0-water, 1-unvisited island, 2-visited island
        // modified from my solution of Leetcode 695. Max Area of Island
        int mx=0, i, j;
        stack<pair<int,int>> st;
        for(int r=0; r!=grid.size(); r++){
            for(int c=0; c!=grid[0].size(); c++){
                if(grid[r][c]=='1'){
                    mx++;
                    st.push(make_pair(r, c));
                    grid[r][c]='2';
                    while(!st.empty()){
                        i=st.top().first;
                        j=st.top().second;
                        st.pop();
                        if(-1<i-1&&grid[i-1][j]=='1'){
                            st.push(make_pair(i-1, j));
                            grid[i-1][j]='2';
                        }
                        if(-1<j-1&&grid[i][j-1]=='1'){
                            st.push(make_pair(i, j-1));
                            grid[i][j-1]='2';
                        }
                        if(i+1<grid.size()&&grid[i+1][j]=='1'){
                            st.push(make_pair(i+1, j));
                            grid[i+1][j]='2';
                        }
                        if(j+1<grid[0].size()&&grid[i][j+1]=='1'){
                            st.push(make_pair(i, j+1));
                            grid[i][j+1]='2';
                        }
                        //cout<<i<<","<<j<<" ";
                    }
                }
            }
        }
        
        //for(int i=0; i!=grid.size(); i++){
        //    for(int j=0; j!=grid[0].size(); j++)    cout<<grid[i][j]<<" ";
        //    cout<<endl;
        //}
        
        return mx;
    }
};

