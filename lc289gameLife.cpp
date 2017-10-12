
/*
Leetcode 289. Game of Life

Related Topics 
Array 
Similar Questions 
Set Matrix Zeroes 

Next challenges: Best Time to Buy and Sell Stock, Insert Delete GetRandom O(1), Maximum Swap

Runtime: 3 ms
You are here! 
Your runtime beats 4.68 % of cpp submissions.

Runtime: 0 ms
You are here! 
Your runtime beats 84.00 % of cpp submissions. 

*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0:death->death, 1:live->live, 2:death->live , 3:live->death
        int r=board.size(), c=board[0].size(), sum;
        for(int j=0; j!=c; j++) life( board, 0, j);
        for(int j=0; j!=c; j++) life( board, r-1, j);
        for(int i=1; i!=r; i++) life( board, i, 0);
        for(int i=1; i!=r; i++) life( board, i, c-1);                   
            
        for(int i=1; i<r-1; i++ ){
            for(int j=1; j<c-1; j++){
                sum = 0;
                if( board[i-1][j-1]==1 || board[i-1][j-1]==3 )    ++sum;
                if( board[i-1][j]==1 || board[i-1][j]==3 )    ++sum;
                if( board[i-1][j+1]==1 || board[i-1][j+1]==3 )    ++sum;
                if( board[i][j+1]==1 || board[i][j+1]==3 )    ++sum;
                if( board[i+1][j+1]==1 || board[i+1][j+1]==3 )    ++sum;
                if( board[i+1][j]==1 || board[i+1][j]==3 )    ++sum;
                if( board[i+1][j-1]==1 || board[i+1][j-1]==3 )    ++sum;
                if( board[i][j-1]==1 || board[i][j-1]==3 )    ++sum;
                if( board[i][j]==0 ){
                    if( sum==3 )    board[i][j]=2;
                }else{
                    if( sum<2 || 3<sum) board[i][j]=3;
                }
            }
        }
                   
        for(int i=0; i!=board.size(); i++){
            for(int j=0; j!=board[0].size(); j++){
                // cout<<board[i][j]<<' ';
                if(board[i][j]==2){
                    board[i][j]=1;
                }else if(board[i][j]==3){
                    board[i][j]=0;
                }
            }
            // cout<<endl;
        }
        
        return ;
    }
    
    
    void life(vector<vector<int>>& board, int i, int j){
        int sum=0, r=board.size(), c=board[0].size();        
        // clockwise from 12 o'clock
        if( -1<i-1 && (board[i-1][j]==1 || board[i-1][j]==3) )    ++sum;
        if( -1<i-1 && j+1<c && (board[i-1][j+1]==1 || board[i-1][j+1]==3) )    ++sum;
        if( j+1<c && (board[i][j+1]==1 || board[i][j+1]==3) )    ++sum;
        if( i+1<r && j+1<c && (board[i+1][j+1]==1 || board[i+1][j+1]==3) )    ++sum;
        if( i+1<r && (board[i+1][j]==1 || board[i+1][j]==3) )    ++sum;
        if( i+1<r && -1<j-1 && (board[i+1][j-1]==1 || board[i+1][j-1]==3) )    ++sum;
        if( -1<j-1 && (board[i][j-1]==1 || board[i][j-1]==3) )    ++sum;
        if( -1<i-1 && -1<j-1 && (board[i-1][j-1]==1 || board[i-1][j-1]==3) )    ++sum;        
        if( board[i][j]==0 ){
            if( sum==3 )    board[i][j]=2;
        }else{
            if( sum<2 || 3<sum) board[i][j]=3;
        }
    }
    
};

