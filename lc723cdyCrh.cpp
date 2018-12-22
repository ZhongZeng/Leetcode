/*
723. Candy Crush

Related Topics: Array, Two Pointers 

Test Cases:
[[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
[[1,1,1],[2,1,2],[2,1,2]]
[[1,2,3],[4,5,6],[7,8,9]]

Runtime: 16 ms, faster than 100.00% of C++ online submissions for Candy Crush.
*/

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        // O(m*n*k) time, O(1) space 
        bool b=true;
        int i, j, k;
        vector<int> vb(board[0].size(),-1);// lowest row w/ consecutive 0s to top
        
        while(b){
            b=false;
            for( i=0; i<board.size(); i++){// rows
                for( j=1; j<board[i].size()-1; j++){
                   if(board[i][j]!=0&&abs(board[i][j])==abs(board[i][j-1])&&abs(board[i][j])==abs(board[i][j+1])){
                       board[i][j-1]=-abs(board[i][j]);
                       board[i][j]=-abs(board[i][j]);
                       board[i][j+1]=-abs(board[i][j]);
                   }
                }
            }
            
            for( j=0; j<board[0].size(); j++){// columns
                for( i=board.size()-2; vb[j]+1<i; i--){
                   if(board[i][j]!=0&&abs(board[i][j])==abs(board[i-1][j])&&abs(board[i][j])==abs(board[i+1][j])){
                       board[i-1][j]=-abs(board[i][j]);
                       board[i][j]=-abs(board[i][j]);
                       board[i+1][j]=-abs(board[i][j]);
                   }
                }
            }
            // for(auto e:board){for(auto f:e)   cout<<f<<" ";   cout<<endl;}
            
            for( j=0; j<board[0].size(); j++){// 2-pointer to fill empty cells
                for( k=board.size()-1, i=board.size()-1; vb[j]<i; i--){
                    if(0<board[i][j])   board[k--][j]=board[i][j];
                }
                if(i!=k)    b=true;// i==vb[j]
                vb[j]=k;
                for( ; i<k; k--)    board[k][j]=0;
            }
        }
        
        return board;
    }
};
