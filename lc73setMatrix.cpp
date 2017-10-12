
/*
Leetcode 73. Set Matrix Zeroes

Related Topics 
Array 
Similar Questions 
Game of Life 

Next challenges: Word Ladder II, Longest Line of Consecutive One in Matrix, K Empty Slots

Test Cases:
[[0]]
[[1,1,1,1],[0,1,1,1],[1,1,1,1],[1,1,1,0],[1,1,1,1]]
[[0,1]]

157 / 157 test cases passed.
Status: Accepted
Runtime: 56 ms
You are here! 
Your runtime beats 45.99 % of cpp submissions

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(), c=matrix[0].size(), r1=1, c1=1;
        // find 0s in 1st row
        for(int j=0; j!=c; j++){
            if(matrix[0][j]==0){
                r1=0;
                break;
            }
        }
        
        // find 0s in 1st col
        for(int i=0; i!=r; i++){
            if(matrix[i][0]==0){
                c1=0;
                break;
            }
        }
        
        // find 0s from [1][1] to [r-1][c-1]
        for( int i=1; i!=r; i++ ){
            for( int j=1; j!=c; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        /*// cout the matrix 
        for( int i=0; i!=r; i++ ){
            for( int j=0; j!=c; j++){
                cout<<matrix[i][j]<<' ';
            }
            cout<<endl;
        }*/
        
        // make cols & rows 0s
        for(int j=1; j!=c; j++){
            if(matrix[0][j]==0){
                for(int i=1; i!=r; i++) matrix[i][j]=0;
            }
        }        
        
        for(int i=1; i!=r; i++){
            if(matrix[i][0]==0){
                for(int j=1; j!=c; j++) matrix[i][j]=0;
            }
        }  
        
        if(r1==0)   for(int j=0; j!=c; j++) matrix[0][j]=0;
        if(c1==0)   for(int i=0; i!=r; i++) matrix[i][0]=0;
        
        return ;
    }
};
