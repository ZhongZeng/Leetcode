

/*
Leetcode 695. Max Area of Island

Related Topics 
Array, Depth-first Search
Similar Questions 
Number of IslandsIsland Perimeter

Next challenges: Number of Islands

Test Case:
[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]

Runtime: 25 ms
Your runtime beats 52.33 % of cpp submissions.

*/




class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // DFS, O(m*n) time 
        // 0-water, 1-unvisited island, 2-visited island
        int mx=0, t;
        stack<pair<int,int>> st;
        for(int i=0; i!=grid.size(); i++){
            for(int j=0; j!=grid[0].size(); j++){
                if(grid[i][j]==1){
                    t=0;
                    st.push(make_pair(i, j));
                    grid[i][j]=2;
                    while(!st.empty()){
                        i=st.top().first;
                        j=st.top().second;
                        st.pop();
                        t++;
                        if(-1<i-1&&grid[i-1][j]==1){
                            st.push(make_pair(i-1, j));
                            grid[i-1][j]=2;
                        }
                        if(-1<j-1&&grid[i][j-1]==1){
                            st.push(make_pair(i, j-1));
                            grid[i][j-1]=2;
                        }
                        if(i+1<grid.size()&&grid[i+1][j]==1){
                            st.push(make_pair(i+1, j));
                            grid[i+1][j]=2;
                        }
                        if(j+1<grid[0].size()&&grid[i][j+1]==1){
                            st.push(make_pair(i, j+1));
                            grid[i][j+1]=2;
                        }
                        //cout<<i<<","<<j<<" ";
                    }
                    mx=mx<t?t:mx;
                }
            }
        }
        
        return mx;
    }
};