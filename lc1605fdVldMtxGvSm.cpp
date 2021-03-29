/*
1605. Find Valid Matrix Given Row and Column Sums

Companies:	Google
Related Topics:	Greedy
Similar Questions: Reconstruct a 2-Row Binary Matrix

Runtime: 76 ms	Your runtime beats 50.36 % of cpp submissions.
Memory Usage: 33.4 MB	Your memory usage beats 66.75 % of cpp submissions.
*/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // Greedy; sum(rowSum)==sum(colSum)
        vector<vector<int>> rt(rowSum.size(), vector<int> (colSum.size(),0) );
        
        for( int i=0; i<rowSum.size(); i++){
            for( int j=0; j<colSum.size(); j++){
                int t=rowSum[i]<colSum[j]?rowSum[i]:colSum[j];// sum of each row&col <= each rowSum&colSum
                rt[i][j]=t;
                rowSum[i]-=t;
                colSum[j]-=t;
            }
        }
        
        return rt;
    }
};