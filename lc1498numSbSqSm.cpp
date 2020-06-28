/*
1498. Number of Subsequences That Satisfy the Given Sum Condition

Medium
Companies	Google
Related Topics	Sort, Sliding Window

Test Cases:
[3,5,6,7]
9
[3,3,6,8]
10
[2,3,3,4,6,7]
12
[5,2,4,1,7,6,8]
16
[14,4,6,6,20,8,5,6,8,12,6,10,14,9,17,16,9,7,14,11,14,15,13,11,10,18,13,17,17,14,17,7,9,5,10,13,8,5,18,20,7,5,5,15,19,14]
22

Runtime: 324 ms	Your runtime beats 100.00 % of cpp submissions
Memory Usage: 50 MB

https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/discuss/709480/C++-O(n*log(n))-Two-Pointer
*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // O(n*log(n)) time, O(n) space; Two Pointer, sort
        int sum=0;
        vector<int> lens(nums.size(), 0);
        sort( nums.begin(), nums.end());
        
        for( int b=0, e=nums.size()-1; b<=e; ){
            if(nums[b]+nums[e]<=target) lens[e-b++]+=1;// [b,k) k in (b,e]
            else    e--;
        }
        
        for( int i=0, count=1; i<lens.size(); i++, count=(count<<1)%1000000007)
            sum=(sum+lens[i]*count)%1000000007;
        
        return sum;
    }
};