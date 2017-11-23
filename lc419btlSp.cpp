

/*
Leetcode 419. Battleships in a Board

Next challenges: Validate Binary Search Tree, Gas Station, Falling Squares

Test Cases:
[[]]
[["X",".","X"]]
[["X","X","X"]]
[["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]

Runtime: 9 ms
You are here! 
Your runtime beats 8.95 % of cpp submissions.

Runtime: 6 ms
You are here! 
Your runtime beats 28.28 % of cpp submissions.

*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size()<1)  return 0;
        if(board[0].size()<1)  return 0;
        
        int c=0;
        if(board[0][0]!='.')    c++;
        
        for(int i=1; i!=board[0].size(); i++){
            if(board[0][i]!='.' && board[0][i-1]=='.')  c++;
        }
        
        for(int i=1; i!=board.size(); i++){
            if(board[i][0]!='.' && board[i-1][0]=='.')  c++;
        }      
        
        for(int i=1; i!=board.size(); i++){
            for(int j=1; j!=board[0].size(); j++){
                if( board[i][j]!='.' && board[i-1][j]=='.' && board[i][j-1]=='.' )
                        c++;
            }
        }
        return c;
    }
};
