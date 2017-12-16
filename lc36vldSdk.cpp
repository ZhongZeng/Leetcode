
/*

Leetcode 36. Valid Sudoku

Related Topics 
Hash Table
Similar Questions 
Sudoku Solver

Next challenges: Sudoku Solver

Test Caes:
[[".","8","7","6","5","4","3","2","1"],["2",".",".",".",".",".",".",".","."],["3",".",".",".",".",".",".",".","."],["4",".",".",".",".",".",".",".","."],["5",".",".",".",".",".",".",".","."],["6",".",".",".",".",".",".",".","."],["7",".",".",".",".",".",".",".","."],["8",".",".",".",".",".",".",".","."],["9",".",".",".",".",".",".",".","."]]

Runtime: 22 ms
Your runtime beats 17.29 % of cpp submissions.

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> us;
        unordered_set<int>::iterator usi;
        vector<unordered_set<int>> row(9,us),col(9,us);
        
        
        unordered_map<int,unordered_set<int>> um;
        unordered_map<int,unordered_set<int>>::iterator umi;
        vector<unordered_map<int,unordered_set<int>>> nin(9,um);
        
        for(int i=0; i!=board.size(); i++){
            for(int j=0; j!=board[0].size(); j++){
                if(board[i][j]!='.'){
                    // row #
                    usi=row[board[i][j]-'1'].find(i);
                    if(usi!=row[board[i][j]-'1'].end()) return false;
                    else    row[board[i][j]-'1'].emplace(i);
                        
                    // col # 
                    usi=col[board[i][j]-'1'].find(j);
                    if(usi!=col[board[i][j]-'1'].end()) return false;
                    else    col[board[i][j]-'1'].emplace(j);
                    
                    // 9-board #
                    umi=nin[board[i][j]-'1'].find(i/3);
                    if(umi!=nin[board[i][j]-'1'].end()){
                        usi=umi->second.find(j/3);
                        if(usi!=umi->second.end())  return false;
                        else    umi->second.emplace(j/3);
                    }else{
                        us.clear();
                        us.emplace(j/3);
                        nin[board[i][j]-'1'].emplace(i/3,us);
                    }
                }
            }
        }
        
        return true;
    }
};
