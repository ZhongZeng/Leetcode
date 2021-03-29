/*
1599. Maximum Profit of Operating a Centennial Wheel

Companies	peak6
Related Topics	Greedy

Runtime: 320 ms
Memory Usage: 81.6 MB	Your memory usage beats 7.27 % of cpp submissions.
*/

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        // Greedy 
        if(4*boardingCost<=runningCost) return -1;
        int profit=0, max_profit=0, min_rotate=-1, customer=0, rotates=0;
        
        for( int i=0; i<customers.size(); i++){
            customer+=customers[i];
            calculateProfit( profit, customer, rotates, 1, boardingCost, runningCost);
            updateMaxProfit( profit, rotates, max_profit, min_rotate);
        }

        calculateProfit( profit, customer, rotates, customer/4, boardingCost, runningCost);
        updateMaxProfit( profit, rotates, max_profit, min_rotate);
        
        if(0<customer){
            calculateProfit( profit, customer, rotates, 1, boardingCost, runningCost);
            updateMaxProfit( profit, rotates, max_profit, min_rotate);
        }
        
        return min_rotate;
    }
    
protected:
    void calculateProfit( int & profit, int & customer, int & rotates, 
            int rotate, int boardingCost, int runningCost){
        int c=customer<rotate*4?customer:rotate*4;
        profit+=c*boardingCost-rotate*runningCost;
        customer-=c;
        rotates+=rotate;
        return ;
    }
    
    void updateMaxProfit( int profit, int rotates, int & max_profit, int & min_rotate){
        if(max_profit<profit){
            max_profit=profit;
            min_rotate=rotates;
        }
        return ;
    }
};