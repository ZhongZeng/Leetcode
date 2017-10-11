
/*
Leetcode 661. Image Smoother

Related Topics 
Array 

Next challenges: Combination Sum II, Shortest Word Distance, Game of Life

Test Cases:
[[1]]
[[1,1,1],[1,0,1],[1,1,1]]

Runtime: 192 ms
You are here! 
Your runtime beats 31.26 % of cpp submissions

*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int r=M.size(), c=M[0].size();
        
        vector<vector<int>> vcvc( r, vector<int>( c,0));
        // cout<<vcvc.size()<<' '<<vcvc[0].size()<<endl;
        vcvc[0][0] = genSmo( M, 0, 0); // (M[0][1]+M[1][1]+M[1][0]) / 3;
        vcvc[0][c-1] = genSmo( M, 0, c-1); // (M[0][c-2]+M[1][c-2]+M[1][c-1]) / 3;
        vcvc[r-1][0] = genSmo( M, r-1, 0); // (M[r-2][0]+M[r-2][1]+M[r-1][1]) / 3;
        vcvc[r-1][c-1] = genSmo( M, r-1, c-1); // (M[r-2][c-2]+M[r-2][c-1]+M[r-1][c-2]) / 3;        
        
        for(int i=1; i<c-1; i++)  vcvc[0][i] = genSmo( M, 0, i); // (M[0][i-1]+M[1][i-1]+M[1][i]+M[1][i+1]+M[0][i+1]) / 5;
        for(int i=1; i<c-1; i++)  vcvc[r-1][i] = genSmo( M, r-1, i); // (M[r-1][i-1]+M[r-2][i-1]+M[r-2][i]+M[r-2][i+1]+M[r-1][i+1]) / 5;
        for(int i=1; i<r-1; i++)  vcvc[i][0] = genSmo( M, i, 0); // ( M[i-1][0]+M[i-1][1]+M[i][1]+M[i+1][1]+M[i+1][0] ) / 5;
        for(int i=1; i<r-1; i++)  vcvc[i][c-1] = genSmo( M, i, c-1); // ( M[i-1][r-1]+M[i-1][r-2]+M[i][r-2]+M[i+1][r-2]+M[i+1][r-1] ) / 5; 
        
        for(int i=1; i<r-1; i++ ){
            for( int j=1; j<c-1; j++ ){
                vcvc[i][j] = ( M[i][j] + M[i+1][j+1] + M[i+1][j-1] + M[i+1][j] + M[i][j+1]
                              + M[i][j-1] + M[i-1][j+1] + M[i-1][j] + M[i-1][j-1] )/9 ;
            }
        }
        
        return vcvc;
    }
    
    int genSmo(vector<vector<int>>& M, int i, int j){
        // cout<<"genSmo"<<endl;
        int r=M.size(), c=M[0].size(), sum=M[i][j], cnt=1;
        if( -1<i-1 && -1<j-1 ){   sum+=M[i-1][j-1]; ++cnt;}
        if( -1<i-1 ){   sum+=M[i-1][j]; ++cnt;}
        if( -1<i-1 && j+1<c ){   sum+=M[i-1][j+1];   ++cnt;}
        if( j+1<c ){   sum+=M[i][j+1];   ++cnt;}
        if( i+1<r && j+1<c ){   sum+=M[i+1][j+1];    ++cnt;}
        if( i+1<r ){   sum+=M[i+1][j];   ++cnt;}
        if( i+1<r && -1<j-1){   sum+=M[i+1][j-1];    ++cnt;}
        if( -1<j-1){   sum+=M[i][j-1];   ++cnt;}
        return sum/cnt;
    }
    
};

