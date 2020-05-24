/*
1277. Count Square Submatrices with All Ones

Related Company: Google
Related Topics: Array, Dynamic Programming

Test Cases:
[[0,1,1,1],[1,1,1,1],[0,1,1,1]]

Runtime: 212 ms, faster than 30.62% of C++ online submissions for Count Square Submatrices with All Ones.
Runtime: 224 ms, faster than 27.24% of C++ online submissions for Count Square Submatrices with All Ones.
Memory Usage: 26.4 MB, less than 100.00% of C++ online submissions for Count Square Submatrices with All Ones.

Next challenges: Shortest Common Supersequence, Find Numbers with Even Number of Digits,
The K Weakest Rows in a Matrix

https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/648074/C++-DP-O(m*n)-TimeandSpace-with-Explanation
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
		// DP, O(m*n) time&space
		if(matrix.size()<1||matrix[0].size()<1)	return 0;
		int sum=0, s;
        vector<vector<int>> sq(matrix.size()+1, vector<int> (matrix[0].size()+1, 0));
		// sq[i][j]: side of largest square w/ all 1s & right bottom at matrix[i-1][j-1]
		
		for( int i=0; i<matrix.size(); i++){
			for( int j=0; j<matrix[0].size(); j++){
				if(matrix[i][j]==1){
					if(sq[i][j+1]<sq[i+1][j])	s=sq[i][j+1]+1;
					else if(sq[i+1][j]<sq[i][j+1])	s=sq[i+1][j]+1;
					else	s=sq[i+1][j]+(matrix[i-sq[i+1][j]][j-sq[i+1][j]]==0?0:1);
					sum+=s;
					sq[i+1][j+1]=s;
				}
			}
		}
		
		return sum;
    }
	
/*protected:
	int calTotalSqures( int s){
		// calculate all squares in square of s=s*s+(s-1)*(s-1)+...+1=s*(s+1)*(2*s+1)/6
		// DP can also calculate this w/ average O(1) max O(s) time 
		return s*(s+1)*(2*s+1)/6;
	}*/
};