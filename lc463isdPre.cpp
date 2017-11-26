

/*
Leetcode 463. Island Perimeter

Related Topics 
Hash Table 
Similar Questions 
Max Area of Island 

Next challenges: Max Area of Island

Test Case:
[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]

Runtime: 139 ms
You are here! 
Your runtime beats 74.58 % of cpp submissions.

DFS & BFS can also do this without checking every cell 

*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // Why is the tag hash_table? 
        int sum=0;
     
        for(int i=1; i<grid.size()-1; i++)   Per( i, 0, sum, grid ); // 1st column w/t nodes        
        
        if( 1<grid[0].size() ){
            for(int i=1; i<grid.size()-1; i++){   
                Per( i, grid[i].size()-1, sum, grid ); // last column w/t nodes
            }
        }
        
        for(int j=0; j<grid[0].size(); j++)   Per( 0, j, sum, grid ); // 1st row 
        
        if( 1<grid.size() ){
            for(int j=0; j<grid[0].size(); j++){   
                Per( grid.size()-1, j, sum, grid ); // last row
            }
        }        
        //cout<<sum<<endl;
        
        for(int i=1; i<grid.size()-1; i++){
            for(int j=1; j<grid[i].size()-1; j++){
                if( grid[i][j]!=0 ){
                    if( grid[i-1][j]!=1 )   sum++;
                    if( grid[i+1][j]!=1 )   sum++;
                    if( grid[i][j-1]!=1 )   sum++;
                    if( grid[i][j+1]!=1 )   sum++;
                }                
            }
        }
        
        return sum; 
    }
    
protected:
    void Per( int i, int j, int & sum, vector<vector<int>>& grid ){
        if( grid[i][j]!=0 ){
            if( -1<i-1 ){
                sum += grid[i-1][j]!=0 ? 0 : 1 ;
            }else{
                sum++;
            }
            
            if( -1<j-1 ){
                sum += grid[i][j-1]!=0 ? 0 : 1 ;
            }else{
                sum++;
            }
            
            if( i+1<grid.size() ){
                sum += grid[i+1][j]!=0 ? 0 : 1 ;
            }else{
                sum++;
            }
            
            if( j+1<grid[i].size() ){
                sum += grid[i][j+1]!=0 ? 0 : 1 ;
            }else{
                sum++;
            }                        
        }        
        //cout<<i<<' '<<j<<' '<<sum<<endl;        
        return ;
    }
    
};
