
/*
Leetcode 89. Gray Code

Companies 
Amazon
Related Topics 
Backtracking 
Similar Questions 
1-bit and 2-bit Characters

Test Cases:
2
4

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

Next challenges: Sudoku Solver, Binary WatchWord Squares

*/

class Solution {
public:
    vector<int> grayCode(int n) {
        // DP, backtrack 
        vector<int> rt={0};
        int len, t=1;
        
        for( int i=0; i<n; i++){
            len=rt.size();
            for( int j=len-1; -1<j; j--)    rt.push_back(rt[j]+t);
            t=t<<1;
        }
        
        return rt;
    }
};
