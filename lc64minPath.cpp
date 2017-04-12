
/*
Leetcode 64. Minimum Path Sum
Apr 10, 2017 @Jersey City, NJ
You are here! 
Your runtime beats 16.25% of cpp submissions. 12 ms
Your runtime beats 24.23% of cpp submissions. 9 ms
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=1;
        if(row!=0) col=grid[0].size();
        
        for(int i=row-1; i!=0; i--){// the last column
            grid[i-1][col-1] += grid[i][col-1];
            //cout<<grid[i-1][col-1]<<endl;
        }
        
        for(int i=col-1; i!=0; i--){// the last row
            grid[row-1][i-1] += grid[row-1][i];
            //cout<<grid[row-1][i-1]<<endl;
        }
        
        for(int i=row-1; i!=0; i--){
            for(int j=col-1; j!=0; j--){
                grid[i-1][j-1] += min(grid[i][j-1], grid[i-1][j]);
                //cout<<grid[i-1][j-1]<<endl;
            }
        }
        
        return grid[0][0];
    }
};

int main(){

	return 0;
}