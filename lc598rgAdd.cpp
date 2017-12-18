
/*
Leetcode 598. Range Addition II

Related Topics 
Math
Similar Questions 
Range Addition

Test Cases:
3
3
[[2,2],[3,3]]
4
5
[[2,3],[4,2]]
3
3
[]

Runtime: 6 ms
Your runtime beats 67.27 % of cpp submissions.

*/


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r=m, c=n;
        for(int i=0; i!=ops.size(); i++){
            if(ops[i][0]!=0&&ops[i][0]<r)   r=ops[i][0];
            if(ops[i][1]!=0&&ops[i][1]<c)   c=ops[i][1];
        }
        
        return r*c;
    }
};