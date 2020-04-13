/*
1393. Capital Gain/Loss

Companies	Rohinhood

Runtime: 694 ms, faster than 15.92% of MySQL online submissions for Capital Gain/Loss.
Memory Usage: 0B, less than 100.00% of MySQL online submissions for Capital Gain/Loss.
Next challenges: Find Customer Referee, Active Businesses, Last Person to Fit in the Elevator

https://leetcode.com/problems/capital-gainloss/discuss/577260/MySQL-IF%2BSUM
*/

# Write your MySQL query statement below
select stock_name
, sum( price * if(operation='Sell',1,-1) ) as capital_gain_loss
from Stocks
group by stock_name