/*
1475. Final Prices With a Special Discount in a Shop

Ranking of Biweekly Contest 28  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
2792 / 8571	zhongzeng 	7	0:15:37	 0:08:32	 0:15:37	

Easy
Companies	Dream11
Related Topics	Array

Test Cases:
[8,4,6,2,3]
[1,2,3,4,5]
[10,1,1,6]

Runtime: 20 ms
Memory Usage: 10.3 MB
*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // stack, O(n) time
        vector<int> pays, indices;
        
        for( int i=0; i<prices.size(); i++){
            for( ; 0<indices.size()&&prices[i]<=prices[indices.back()]; indices.pop_back())//prices[indices] ascending
                pays[indices.back()]-=prices[i];
            pays.push_back(prices[i]);
            indices.push_back(i);
        }
        
        return pays;
    }
};