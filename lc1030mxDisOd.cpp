/*
1030. Matrix Cells in Distance Order

Companies	Yahoo
Related Topics	Sort

Test Cases:
1
2
0
0
2
2
0
1
2
3
1
2

Runtime: 108 ms
Memory Usage: 20.3 MB
*/

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        // O(R*C) time; R, C in [1,100] 
        vector<int> vc={r0, c0};
        vector<vector<int>> rt;
        rt.push_back(vc);
        int mx=(r0<R-r0?R-r0:r0)+(c0<C-c0?C-c0:c0);
        
        for( int d=1; d<=mx; d++){
            add0(R,C,r0,c0+d, rt);
            add0(R,C,r0,c0-d, rt);
            add0(R,C,r0+d,c0, rt);
            add0(R,C,r0-d,c0, rt);
            for( int i=1; i<d; i++){
                int j=d-i;
                add0(R,C,r0+i,c0+j, rt);
                add0(R,C,r0+i,c0-j, rt);
                add0(R,C,r0-i,c0+j, rt);
                add0(R,C,r0-i,c0-j, rt);
            }
        }
        
        return rt;
    }
    
protected:
    void add0( int& R, int& C, int r, int c, vector<vector<int>>& rt){
        if(r<R&&c<C&&-1<r&&-1<c){
            vector<int> vc={r,c};
            rt.push_back(vc);
        }
        return ;
    }
};