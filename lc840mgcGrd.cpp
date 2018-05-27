
/*

Leetcode 840. Magic Squares In Grid

Companies 
Google
Related Topics 
Array 

Test Cases:
[[4,3,8,4],[9,5,1,9],[2,7,6,2]]
[[10,3,5],[1,6,11],[7,9,2]]
[[6,0,8,1,6],[8,3,7,8,3],[1,11,6,1,4],[8,4,5,9,8],[8,1,10,4,6]]
[[7,0,5],[2,4,6],[3,8,1]]

Runtime: 5 ms

*/

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // backtrack, O(n*m) time
        // 3 x 3 grid, distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum 
        // 1 <= grid.length = grid[0].length <= 10
        // 0 <= grid[i][j] <= 15
        int rt=0;
        
        for(int i=0; i+2<grid.size(); i++){
            for(int j=0; j+2<grid[0].size(); j++){
                if(isMg(grid, i, j))    rt++;
            }
        }
        
        return rt;
    }
    
    bool isMg(vector<vector<int>>& grid, int i, int j){
        int s=0, t=0, k, l;
        vector<int> vn(10, 0);
        for( k=0; k<3; k++) s+=grid[i+k][j+k];
        for( k=0; k<3; k++) t+=grid[i+k][j+2-k];
        if(s!=t)    return false;
        //cout<<i<<","<<j<<" ";
        
        for( k=0; k<3; k++){// each row 
            t=0;
            for( l=0; l<3; l++) t+=grid[i+k][j+l];
            if(s!=t)    return false;
        }
        
        for( k=0; k<3; k++){// each column 
            t=0;
            for( l=0; l<3; l++) t+=grid[i+l][j+k];
            if(s!=t)    return false;
        }
        
        for( k=0; k<3; k++){
            for( l=0; l<3; l++){
                if(grid[i+k][j+l]<1||9<grid[i+k][j+l]||vn[grid[i+k][j+l]]!=0)   return false;
                else    vn[grid[i+k][j+l]]=1;
            }
        }
        
        return true;
    }
};
