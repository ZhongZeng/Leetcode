
/*
Leetcode 807. Max Increase to Keep City Skyline

Weekly Contest 77  

Test Case:
[[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]

*/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // only need to keep 2 directions; O(m*n) time
        vector<int> vr, vc;
        int mx, sum=0;
        
        for(int i=0; i<grid.size(); i++){
            mx=grid[i][0];
            for(int j=1; j<grid[0].size(); j++) if(mx<grid[i][j])   mx=grid[i][j];
            vr.push_back(mx);
        }
        
        for(int j=0; j<grid[0].size(); j++){
            mx=grid[0][j];
            for(int i=1; i<grid.size(); i++)    if(mx<grid[i][j])   mx=grid[i][j];
            vc.push_back(mx);
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]<vr[i]&&grid[i][j]<vc[j]){
                    if(vr[i]<vc[j]) sum+=vr[i]-grid[i][j];
                    else    sum+=vc[j]-grid[i][j];
                }
            }
        }
        
        return sum;
    }
};
