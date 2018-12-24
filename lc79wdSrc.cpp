
/*
79. Word Search

Related Topics: Array, Backtracking
Similiar Questions: Word Search II

Test Cases:
[["b","a","a","b","a","b"],["a","b","a","a","a","a"],["a","b","a","a","a","b"],["a","b","a","b","b","a"],["a","a","b","b","a","b"],["a","a","b","b","b","a"],["a","a","b","a","a","b"]]
"aabbbbabbaababaaaabababbaaba"
[["a","a","a"]]
"aaaa"
[["a"]]
"ab"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
[["a"]]
"a"
*/

// Runtime: 12 ms, faster than 98.59% of C++ online submissions for Word Search.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // backtrack, O(m*n*k) time; inspired from Discuss, modify board in-place 
        if(board.size()<1||board[0].size()<1)   return word.size()<1;
        
        for( int i=0; i<board.size(); i++){
            for( int j=0; j<board[0].size(); j++){
                if(dfs(i,j,board,0,word))    return true;
            }
        }
        
        return false;
    }
    
    bool dfs( int i, int j, vector<vector<char>>& board, int t, string& word){
        if(board[i][j]==(char)127){// '\0' other special char also ok
            return false;
        }else{
            if(board[i][j]==word[t]){
                char c=board[i][j];
                board[i][j]=(char)127;                
                if(t+1==word.size()) return true;
                if(0<i&&dfs(i-1,j,board,t+1,word))   return true;
                if(i<board.size()-1&&dfs(i+1,j,board,t+1,word))  return true;
                if(0<j&&dfs(i,j-1,board,t+1,word))   return true;
                if(j<board[0].size()-1&&dfs(i,j+1,board,t+1,word))   return true;
                board[i][j]=c;
            }
        }
        return false;
    }
};

// Runtime: 256 ms, faster than 11.61% of C++ online submissions for Word Search.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // backtrack, O(m*m*n*n) time 
        if(board.size()<1||board[0].size()<1)   return word.size()<1;
        
        for( int i=0; i<board.size(); i++){
            for( int j=0; j<board[0].size(); j++){
                vector<int> vc(board[0].size(),0);
                vector<vector<int>> vu(board.size(),vc);
                if(dfs(i,j,board,0,word,vu))    return true;
            }
        }
        
        return false;
    }
    
    bool dfs( int i, int j, vector<vector<char>>& board, int t, string& word, vector<vector<int>>& vu){
        if(vu[i][j]==1){
            return false;
        }else{
            vu[i][j]=1;
            if(board[i][j]==word[t]){
                if(t+1==word.size()) return true;
                if(0<i&&dfs(i-1,j,board,t+1,word,vu))   return true;
                if(i<board.size()-1&&dfs(i+1,j,board,t+1,word,vu))  return true;
                if(0<j&&dfs(i,j-1,board,t+1,word,vu))   return true;
                if(j<board[0].size()-1&&dfs(i,j+1,board,t+1,word,vu))   return true;
            }
            vu[i][j]=0;
        }
        return false;
    }
};