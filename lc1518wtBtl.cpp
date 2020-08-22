/*
1518. Water Bottles

Easy
Companies	Microsoft
Related Topics	Greedy

Test Cases:
9
3
15
4
5
5
2
3

Runtime: 0 ms
Memory Usage: 6.1 MB
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // O(log(bottles)/log(exchanges))
        int sum=numBottles, t;// t: empty bottles
        for( t=numBottles; numExchange<=t; t=t/numExchange+t%numExchange)
            sum+=t/numExchange;
        return sum;
    }
};