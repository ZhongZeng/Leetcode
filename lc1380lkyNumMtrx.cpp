/*
1380. Lucky Numbers in a Matrix

Ranking of Weekly Contest 180  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (4)	Q4 (6)
4398 / 10047	zhongzeng 	7	0:28:11	 0:07:57	 0:28:11	

Companies	Oracle 
Related Topics	Array

Test Cases:
[[3,7,8],[9,11,13],[15,16,17]]
[[1,10,4,2],[9,3,8,7],[15,16,17,12]]

Runtime: 20 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 9.3 MB
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // all elements are distinct
        vector<int> min_in_row, max_in_col, lucky_num;
        
        for( int i=0; i<matrix.size(); i++){
            int idx=0;
            for( int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]<matrix[i][idx]) idx=j;
            }
            min_in_row.push_back(idx);
        }
        
        for( int j=0; j<matrix[0].size(); j++){
            int idx=0;
            for( int i=0; i<matrix.size(); i++){
                if(matrix[idx][j]<matrix[i][j]) idx=i;
            }
            max_in_col.push_back(idx);
        }
        
        for( int i=0; i<min_in_row.size(); i++){
            if(max_in_col[min_in_row[i]]==i)    lucky_num.push_back(matrix[i][min_in_row[i]]);
        }
        
        return lucky_num;
    }
};