
/*
Leetcode 130. Surrounded Regions

Related Topics 
Depth-first Search, Breadth-first Search, Union Find
Similar Questions 
Number of Islands, Walls and Gates

Test Cases:
[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
[]
[["X","O","X","O","X","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]

Runtime: 19 ms
Your runtime beats 48.90 % of cpp submissions.

*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // O(m*n) time
        if(board.size()<1||board[0].size()<1)   return ;
        int r=board.size(), c=board[0].size(); 
        // first fill in all unsurrounded areas of 'O'
        for(int i=0; i<board.size(); i++){
            if(board[i][0]=='O')    findSur( i, 0, board);
        }
        
        for(int i=0; i<board.size(); i++){
            if(board[i][c-1]=='O')  findSur( i, c-1, board);
        }
        
        for(int j=1; j<c-1; j++){
            if(board[0][j]=='O')    findSur( 0, j, board);
        }
        
        for(int j=1; j<c-1; j++){
            if(board[r-1][j]=='O')  findSur( r-1, j, board);
        }
        
        // change filled area and unfilled area
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='P'){
                    board[i][j]='O';
                }    
            }
        }
        
        return ;
    }
    
    void findSur(int m, int n, vector<vector<char>>& board){
        stack<pair<int,int>> st;
        board[m][n]='P';
        st.push(make_pair(m,n));
        while(!st.empty()){
            m=st.top().first;
            n=st.top().second;
            st.pop();
            if(-1<m-1&&board[m-1][n]=='O'){
                board[m-1][n]='P';
                st.push(make_pair(m-1,n));
            }
            if(-1<n-1&&board[m][n-1]=='O'){
                board[m][n-1]='P';
                st.push(make_pair(m,n-1));
            }
            if(m+1<board.size()&&board[m+1][n]=='O'){
                board[m+1][n]='P';
                st.push(make_pair(m+1,n));
            }
            if(n+1<board[0].size()&&board[m][n+1]=='O'){
                board[m][n+1]='P';
                st.push(make_pair(m,n+1));
            }            
        }
        return ;
    }
};
