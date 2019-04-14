/*
999. Available Captures for Rook

Related Topics: Array 

Test Case:
[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
[[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]

Runtime: 4 ms
Memory Usage: 8.6 MB

*/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int sum=0, r, c;
        
        for( int i=0; i<board.size(); i++){
            for( int j=0; j<board[0].size(); j++){
                if(board[i][j]=='R'){
                    r=i;
                    c=j;
                    break;
                }
            }
        }
        
        for( int i=r-1; -1<i; i--){
            if(board[i][c]!='.'){
                if(board[i][c]=='p')    sum+=1;
                break;
            }
        }
        
        for( int j=c-1; -1<j; j--){
            if(board[r][j]!='.'){
                if(board[r][j]=='p')    sum+=1;
                break;
            }
        }
        
        for( int i=r+1; i<board.size(); i++){
            if(board[i][c]!='.'){
                if(board[i][c]=='p')    sum+=1;
                break;
            }
        }
        
        for( int j=c+1; j<board[0].size(); j++){
            if(board[r][j]!='.'){
                if(board[r][j]=='p')    sum+=1;
                break;
            }
        }
        
        return sum;
    }
};