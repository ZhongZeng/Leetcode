
/*
Leetcode 122. Best Time to Buy and Sell Stock II 

Related Topics 
ArrayGreedy
Similar Questions 
Best Time to Buy and Sell Stock, Best Time to Buy and Sell Stock III, 
Best Time to Buy and Sell Stock IV, Best Time to Buy and Sell Stock with Cooldown, 
Best Time to Buy and Sell Stock with Transaction Fee

Next challenges: Best Time to Buy and Sell Stock, 
Best Time to Buy and Sell Stock III, Best Time to Buy and Sell Stock IV, 
Best Time to Buy and Sell Stock with Cooldown, 
Best Time to Buy and Sell Stock with Transaction Fee

Test Cases:
[]
[1,2,3,1,2,32,74,12,0]

Runtime: 6 ms
Your runtime beats 21.92 % of cpp submissions.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // greedy, O(n) time
        int p=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i-1]<prices[i])
                p+=prices[i]-prices[i-1];
        }
        return p;
    }
};
