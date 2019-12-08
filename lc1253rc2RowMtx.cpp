/*
1253. Reconstruct a 2-Row Binary Matrix

Companies	Grab 
Related Topics	Math, Greedy 

Test Cases:
2
1
[1,1,1]
2
3
[2,2,1,1]
5
5
[2,1,2,0,1,0,1,2,0,1]

Runtime: 320 ms	Your runtime beats 25.70 % of cpp submissions.
Memory Usage: 26.5 MB
*/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        // O(n) time&space; array, greedy
        vector<int> vc(colsum.size(),0);
        vector<vector<int>> vv(2,vc), ve;
        
        for( int i=0; i<colsum.size(); i++){
            if(colsum[i]==2){
                vv[0][i]=1;
                upper--;
                vv[1][i]=1;
                lower--;
            }
        }
        
        for( int i=0; i<colsum.size(); i++){
            if(colsum[i]==1){
                if(0<upper){
                    vv[0][i]=1;
                    upper--;
                }else if(0<lower){
                    vv[1][i]=1;
                    lower--;
                }else{
                    return ve;
                }
            }
        }
        
        return upper==0&&lower==0?vv:ve;
    }
};