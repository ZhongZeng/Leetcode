

/*
Leetcode 746. Min Cost Climbing Stairs

Test Cases:
[10, 15, 20]
[1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
[1,2]
[2,1]

*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // DP
        if(cost.size()<2)   return 0;
        int ml=0, mt=0, tp, tq;
        for(int i=2; i!=cost.size()+1; i++){
            tp=ml+cost[i-2];
            tq=mt+cost[i-1];
            ml=mt;
            mt=tp<tq?tp:tq;
        }
        
        return mt;
    }
};
