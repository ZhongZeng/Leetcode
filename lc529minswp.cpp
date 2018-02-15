

/*
Leetcode 529. Minesweeper

Related Topics 
Depth-first Search, Breadth-first Search 

Next challenges: Minimum Height Trees, 
Find Leaves of Binary Tree, The Maze III

Test Cases:
[["M","E","E"],["1","E","E"],["E","1","M"]]
[0,2]
[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]
[3,0]

Runtime: 27 ms
Your runtime beats 71.91 % of cpp submissions.

*/
					
					
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        upBd(board, click[0], click[1]);
        return board;
    }
    
protected:    
    void upBd(vector<vector<char>>& board, int r, int c){
        // 'E'=>'B'or#; 'M'=>'X'
        // Description isn't clear. Try to understand the game yourself. 
		// Once you understand the rule, coding this problem is easy. 
        if(board[r][c]=='E'){
            char sum=numMine(board, r, c);
            if(sum!='0'){
                board[r][c]=sum;
            }else{
                board[r][c]='B';
                if(0<r&&0<c&&board[r-1][c-1]=='E')    upBd(board, r-1, c-1);
                if(0<c&&board[r][c-1]=='E')    upBd(board, r, c-1);
                if(0<r&&board[r-1][c]=='E')    upBd(board, r-1, c);

                if(r<board.size()-1&&c<board[0].size()-1&&board[r+1][c+1]=='E') upBd(board, r+1, c+1);
                if(c<board[0].size()-1&&board[r][c+1]=='E') upBd(board, r, c+1);
                if(r<board.size()-1&&board[r+1][c]=='E')    upBd(board, r+1, c);

                if(r<board.size()-1&&0<c&&board[r+1][c-1]=='E')    upBd(board, r+1, c-1);
                if(c<board[0].size()-1&&0<r&&board[r-1][c+1]=='E') upBd(board, r-1, c+1);                
            }
        }else if(board[r][c]=='M'){
            board[r][c]='X';            
        }// else{} 'B' or number 
        
        return ;        
    }
    
    char numMine(vector<vector<char>>& board, int r, int c){
        int sum=0;
        
        if(0<r&&0<c&&board[r-1][c-1]=='M')    sum++;
        if(0<c&&board[r][c-1]=='M')    sum++;
        if(0<r&&board[r-1][c]=='M')    sum++;
        
        if(r<board.size()-1&&c<board[0].size()-1&&board[r+1][c+1]=='M') sum++;
        if(c<board[0].size()-1&&board[r][c+1]=='M') sum++;
        if(r<board.size()-1&&board[r+1][c]=='M')    sum++;
        
        if(r<board.size()-1&&0<c&&board[r+1][c-1]=='M')    sum++;
        if(c<board[0].size()-1&&0<r&&board[r-1][c+1]=='M') sum++;
        
        //cout<<r<<","<<c<<" ";
        return (char)(sum+'0');
    }
};
					