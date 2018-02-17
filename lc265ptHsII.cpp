
/*
Leetcode 265. Paint House II

Companies 
Facebook
Related Topics 
Dynamic Programming 
Similar Questions 
Product of Array Except Self, Sliding Window Maximum, Paint House, Paint Fence

Next challenges: Paint Fence

Test Cases:
[[1,3,1,4,5],[1,2,3,1,2],[8,9,7,1,3],[1,3,4,5,9],[9,8,3,2,7]]
[[2,4],[7,3],[3,9],[7,3]]
[[17,9,6,2,6,18,8,12,3,5,9,11,20,8,13,16]]
[[8]]
[]

Runtime: 13 ms
Your runtime beats 12.87 % of cpp submissions.
Runtime: 12 ms
Your runtime beats 28.69 % of cpp submissions.

*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        // O(n*k*k) is trivial; O(n*k) time, find 1st&2nd smallest in previous row
        if(costs.size()<1)  return 0;
        if(costs.size()<2){
            int mn=costs[0][0];
            for(int i=1; i<costs[0].size(); i++)    mn=costs[0][i]<mn?costs[0][i]:mn;
            return mn;
        }
        
        vector<int> vc;
        for(int i=1; i<costs.size(); i++){
            vc=m0m1(costs[i-1]);
            for(int j=0; j<costs[0].size(); j++){
                if(j!=vc[2])    costs[i][j]+=vc[0];
                else    costs[i][j]+=vc[1];
            }
        }
        vc=m0m1(costs.back());
        
        return vc[0];
    }
    
    vector<int> m0m1(vector<int>& cost){// v0, v1, loc0, loc1
        vector<int> vc;
        if(cost[0]<cost[1]) vc={cost[0],cost[1],0,1};
        else    vc={cost[1],cost[0],1,0};
        
        for(int i=2; i<cost.size(); i++){
            if(cost[i]<vc[0]){
                vc[1]=vc[0];
                vc[3]=vc[2];
                vc[0]=cost[i];
                vc[2]=i;
            }else if(cost[i]<vc[1]){
                vc[1]=cost[i];
                vc[3]=i;
            }
        }
        return vc;
    }
};