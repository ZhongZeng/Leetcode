
/*
Leetcode 348. Design Tic-Tac-Toe

Companies 
Google, Microsoft 
Related Topics 
Design (Hash Table)

Next challenges: Design Snake Game, 
Design Compressed String Iterator, Design Excel Sum Formula

Test Case:
["TicTacToe","move","move","move","move","move","move","move"]
[[3],[0,0,1],[0,2,2],[2,2,1],[1,1,2],[2,0,1],[1,0,2],[2,1,1]]
["TicTacToe","move","move","move","move","move","move","move","move"]
[[3],[1,1,1],[0,1,2],[0,0,1],[2,2,2],[0,2,1],[2,0,2],[1,0,1],[2,1,2]]
["TicTacToe","move","move","move"]
[[2],[0,1,1],[1,1,2],[1,0,1]]

Runtime: 38 ms
Your runtime beats 14.32 % of cpp submissions.

*/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        m=n;
        unordered_set<int> us;
        //unordered_map<int,unordered_set<int>> um1, um2;// this line is WRONG 
        um1.emplace(m+1,us);
        um1.emplace(m+2,us);    
        um2.emplace(m+1,us);
        um2.emplace(m+2,us);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        // O(1) time 
        if(player<2){//==1
            if(placeX(um1, row+1, col+1))   return 1;
        }else{//===2
            if(placeX(um2, row+1, col+1))   return 2;
        }
        return 0;
    }
    
    bool placeX(unordered_map<int,unordered_set<int>>& um, int i, int j){
        // A move is guaranteed to be valid and is placed on an empty block.
        if(m<2) return true;
        // row
        unordered_map<int,unordered_set<int>>::iterator it=um.find(i);
        if(it!=um.end()){
            it->second.emplace(j);
            if(it->second.size()==m)    return true;
        }else{
            unordered_set<int> us;
            us.emplace(j);
            um.emplace(i,us);
        }
        
        // column
        it=um.find(0-j);// be careful of 0 shared by row&col
        if(it!=um.end()){
            it->second.emplace(0-i); // i is actually okay
            if(it->second.size()==m)    return true;
        }else{
            unordered_set<int> us;
            us.emplace(0-i);
            um.emplace(0-j,us);
        }        
        
        // diagonals 
        if(i==j){
            it=um.find(m+1);
            it->second.emplace(i);
            if(it->second.size()==m)    return true;
        }
        if(i+j==m+1){
            it=um.find(m+2);
            it->second.emplace(i);
            if(it->second.size()==m)    return true;
        }
        return false;
    }
    
    unordered_map<int,unordered_set<int>> um1;// i, j; m+1&m+2 for diagonals
    unordered_map<int,unordered_set<int>> um2;
    int m;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

