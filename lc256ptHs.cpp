
/*
Leetcode 256. Paint House

Companies 
Linkedin
Related Topics 
Dynamic Programming 
Similar Questions 
House Robber, House Robber II, Paint House II, Paint Fence

Next challenges: Paint House II, Paint Fence

Test Cases:
[[1,2,3],[2,1,3],[9,10,8]]
[[1,2,3]]
[]

Runtime: 6 ms
Your runtime beats 8.09 % of cpp submissions. 

*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size()<1)  return 0;
        
        for(int i=1; i<costs.size(); i++){
            costs[i][0]+=costs[i-1][1]<costs[i-1][2]?costs[i-1][1]:costs[i-1][2];
            costs[i][1]+=costs[i-1][0]<costs[i-1][2]?costs[i-1][0]:costs[i-1][2];
            costs[i][2]+=costs[i-1][0]<costs[i-1][1]?costs[i-1][0]:costs[i-1][1];
        }
        //cout<<costs.back()[0]<<" "<<costs.back()[1]<<" "<<costs.back()[2]<<endl;
        
        if(costs.back()[0]<costs.back()[1]){
            if(costs.back()[0]<costs.back()[2]){
                return costs.back()[0];
            }else{
                return costs.back()[2];
            }
        }else{
            if(costs.back()[1]<costs.back()[2]){
                return costs.back()[1];
            }else{
                return costs.back()[2];
            }            
        }
    }
};