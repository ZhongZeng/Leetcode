
/*
Leetcode 794. Valid Tic-Tac-Toe State

Weekly Contest 74  

Suggest Tag: Array 

Test Cases:
["O  ","   ","   "]
["XOX", " X ", "   "]
["XXX", "   ", "OOO"]
["XOX", "O O", "XOX"]
["XOX","X O","X O"]
["XXX","XOO","OO "]

*/

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x=0, o=0, e=0, xc=0, oc=0, i, j;
        bool xw=false, ow=false;
        for( i=0; i<3; i++){// 'X'&&'O'&&empty
            for( j=0; j<3; j++){
                switch(board[i][j]){
                    case 'X': xc++;
                        break ;
                    case 'O': oc++;
                        break ;                     
                }
            }
        }
        if(1<xc-oc||0<oc-xc)    return false;
        
        for( i=0; i<3; i++){// rows
            x=0;
            o=0;
            for( j=0; j<3; j++){
                switch(board[i][j]){
                    case 'X': x++;
                        break ;
                    case 'O': o++;
                        break ;                       
                }                
            }
            if(x==3)    xw=true;
            if(o==3)    ow=true;
        }
        
        for( j=0; j<3; j++){// columns 
            x=0;
            o=0;
            for( i=0; i<3; i++){
                switch(board[i][j]){
                    case 'X': x++;
                        break ;
                    case 'O': o++;
                        break ;                       
                }                
            }
            if(x==3)    xw=true;
            if(o==3)    ow=true;
        }        
        
        for( i=0, x=0, o=0; i<3; i++){// diagonal
            switch(board[i][i]){
                case 'X': x++;
                    break ;
                case 'O': o++;
                    break ;                       
            }                
        }
        if(x==3)    xw=true;
        if(o==3)    ow=true;        
        
        for( i=0, x=0, o=0; i<3; i++){// anti-diagonal
            switch(board[i][2-i]){
                case 'X': x++;
                    break ;
                case 'O': o++;
                    break ;                       
            }                         
        }        
        if(x==3)    xw=true;
        if(o==3)    ow=true;        
        
        if(xw&&ow)  return false;
        else if(xw&&xc-oc!=1)   return false;
        else if(ow&&xc!=oc) return false;
        else    return true;
    }
};
