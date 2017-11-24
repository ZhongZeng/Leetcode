
/*
Leetcode 221. Maximal Square

Related Topics 
Dynamic Programming 
Similar Questions 
Maximal Rectangle 

Next challenges: Maximal Rectangle

Test Cases:
[[]]
[["0","0"],["0","0"]]
[["0","1"],["1","0"]]
[["0","0"],["1","0"]]
[["0","1"],["0","0"]]
[["0","1","1","1","0"]]
[["1","0","0","0","0"]]
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
[["1","1","1","1"],["1","1","1","1"],["1","1","1","1"]]
[["1","0","1","0"],["1","0","1","1"],["1","0","1","1"],["1","1","1","1"]]

Runtime: 19 ms
You are here! 
Your runtime beats 41.03 % of cpp submissions.

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // vector consists of char
        char m='0';
        if(matrix.size()<1 || matrix[0].size()<1){
            return 0;
        }
        
        //scan 1st row
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[0][j]!='0'){
                m='1';
                break;
            }        
        }
        
        //scan 1st col
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0]!='0'){
                m='1';
                break;
            }        
        }        
        
        // scan horizontaly
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){  
                if(matrix[i][j]!='0'){
                    matrix[i][j]=matrix[i][j-1]+1;
                }
                //cout<<matrix[i][j]<<" ";
            }        
            //cout<<endl;
        }
        
        // scan vertically
        for(int j=1; j<matrix[0].size(); j++){
            for(int i=1; i<matrix.size(); i++){                
                if(matrix[i][j]!='0'){
                    matrix[i][j] = matrix[i-1][j]+1<matrix[i][j] ? matrix[i-1][j]+1:matrix[i][j];
                    matrix[i][j] = matrix[i][j-1]+1<matrix[i][j] ? matrix[i][j-1]+1:matrix[i][j];                  
                    matrix[i][j] = matrix[i-1][j-1]+1<matrix[i][j] ? matrix[i-1][j-1]+1:matrix[i][j];
                    m = m < matrix[i][j] ? matrix[i][j]:m;
                }                
                //cout<<matrix[i][j]<<" ";
            }  
            //cout<<endl; 
        }
        
        return (m-'0')*(m-'0');
    }
};