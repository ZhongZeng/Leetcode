
/*
Leetcode 121. Best Time to Buy and Sell Stock

Related Topics 
ArrayDynamic Programming
Similar Questions 
Maximum Subarray, Best Time to Buy and Sell Stock II, 
Best Time to Buy and Sell Stock III, 
Best Time to Buy and Sell Stock IV, 
Best Time to Buy and Sell Stock with Cooldown 

Next challenges: Best Time to Buy and Sell Stock III, 
Best Time to Buy and Sell Stock IV, 
Best Time to Buy and Sell Stock with Cooldown

Test Cases:
[7,1,5,3,6,4]
[5,6,2,4,1]
[]

Runtime: 4 ms, faster than 99.51% of C++ online submissions for Best Time to Buy and Sell Stock.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // O(n) time, O(1) space
        if(prices.size()<2) return 0;
        int profit=0, low=prices[0];
        
        for( int i=1; i<prices.size(); i++){
            if(prices[i]<low){
                low=prices[i];
            }else{
                if(profit<prices[i]-low)    profit=prices[i]-low;
            }
        }
        
        return profit;
    }
};

// Runtime: 9 ms
// Your runtime beats 10.54 % of cpp submissions.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1) return 0;
        int p=0;
        vector<int> vc={prices[0]};// pattern: 2, 3, 1 
        for(int i=1; i<prices.size(); i++){
            if(vc.size()!=2){// ==1
                if(vc[0]<prices[i]){
                    vc.push_back(prices[i]);
                }else{
                    vc[0]=prices[i];
                }
            }else{// vc.size()==2
                if(vc[1]<prices[i]){
                    vc[1]=prices[i];
                }else if(prices[i]<vc[0]){
                    p=p<vc[1]-vc[0]?vc[1]-vc[0]:p;
                    vc.pop_back();
                    vc[0]=prices[i];
                }
            }
        }
        if(vc.size()!=1)   p=p<vc[1]-vc[0]?vc[1]-vc[0]:p;
        return p;
    }
};
