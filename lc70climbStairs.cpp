

/*
Leetcode 70. Climbing Stairs
You are here! 
Your runtime beats 45.60% of cpp submissions. 0 ms
*/

/*
// Time Limit Exceeded
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        else if(n==2) return 2;
        else return climbStairs(n-1)+climbStairs(n-2);
    }
};
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        else if(n==2) return 2;
        
        int ways=0, temp1=1, temp2=2;
        while(1<--n){
            ways = temp1 + temp2;
            temp1 = temp2;
            temp2 = ways;
        }
        return ways;
    }
};