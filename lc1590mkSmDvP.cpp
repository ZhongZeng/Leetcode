/*
1590. Make Sum Divisible by P

Medium
Companies	Amazon
Related Topics	Array, Binary Search

Test Cases:
[1,2,3]
7
[8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2]
148
[3,1,4,2]
6
[6,3,5,2]
9
[1,2,3]
3
[1,2,3]
7
[1000000000,1000000000,1000000000]
3

Runtime: 380 ms, faster than 100.00% of C++ online submissions for Make Sum Divisible by P.
Memory Usage: 67.7 MB, less than 66.67% of C++ online submissions for Make Sum Divisible by P.
Next challenges: Reverse Pairs,
Previous Permutation With One Swap, Decompress Run-Length Encoded List
Next challenges: Max Sum of Rectangle No Larger Than K,
Online Majority Element In Subarray, Max Value of Equation

https://leetcode.com/problems/make-sum-divisible-by-p/discuss/857290/C++-O(n)-Time-Prefix-Beats-100-Time
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // O(n) time, prefix 
        int target=0, min_len=nums.size();
        unordered_map<int,int> prefix={{0,-1}};
        for( int i=0; i<nums.size(); i++)
            target=(target+nums[i])%p;
        
        for( int i=0, sum=0; i<nums.size(); i++){
            sum=(sum+nums[i])%p;
            prefix[sum]=i;
            unordered_map<int,int>::iterator it=prefix.find((sum-target+p)%p);
            if(it!=prefix.end())
                min_len=i-it->second<min_len?i-it->second:min_len;
        }
        
        return min_len!=nums.size()?min_len:-1;    
    }
};