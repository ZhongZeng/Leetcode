/*
1139. Largest 1-Bordered Square

Test Cases:
[[0]]
[[0,1],[1,1]]
[[1,1,1],[1,0,1],[1,1,1]]

Runtime: 28 ms
Memory Usage: 10.8 MB
*/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        // O(n^3) time, similiar to range sum; brute force O(n^4) time
		// Record the number of 1s from 0-index to current position in each row and each column. 
        if(grid.size()==0||grid[0].size()<0)    return 0;
        int rt=0;
        vector<int> r(grid[0].size()+1,0);
        vector<vector<int>> vr(grid.size()+1, r), vc(grid.size()+1, r);
        
        for( int i=0; i<grid.size(); i++){
            for( int j=0; j<grid[0].size(); j++){
                vr[i][j+1]=grid[i][j]+vr[i][j];
            }
        }
        
        for( int j=0; j<grid[0].size(); j++){
            for( int i=0; i<grid.size(); i++){
                vc[i+1][j]=grid[i][j]+vc[i][j];
            }
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                for( int r=0; ; r++){
                    if(i+r<grid.size()&&j+r<grid[0].size()){
                        if(isValidSquare(i, j, i+r, j+r, vr, vc))
                            rt=rt<(r+1)*(r+1)?(r+1)*(r+1):rt;
                    }else{// square too large 
                        break;
                    }
                }
            }
        }
        
        return rt;
    }
    
protected:
    bool isValidSquare( int i0, int j0, int i1, int j1, vector<vector<int>>& vr, vector<vector<int>>& vc){
        if(vc[i1+1][j0]-vc[i0][j0]<i1-i0+1) return false;
        else if(vc[i1+1][j1]-vc[i0][j1]<i1-i0+1) return false;
        else if(vr[i0][j1+1]-vr[i0][j0]<j1-j0+1) return false;
        else if(vr[i1][j1+1]-vr[i1][j0]<j1-j0+1) return false;
        return true;
    }
};