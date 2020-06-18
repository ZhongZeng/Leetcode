/*
5453. Running Sum of 1d Array

Ranking of Weekly Contest 193  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
1342 / 13794	zhongzeng 	12	0:42:12	 0:03:18	 0:09:02  1	 0:37:12

Easy
Companies	Google
Related Topics	Array

Test Cases:
[1,2,3,4]
[1,1,1,1,1]
[3,1,2,10,1]

Runtime: 4 ms	Your runtime beats 80.00 % of cpp submissions.
Memory Usage: 8.9 MB
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Array; O(n) time
        if(nums.size()<1)   return {};
        vector<int> sums={nums[0]};
        for( int i=1; i<nums.size(); i++)
            sums.push_back(sums.back()+nums[i]);
        return sums;
    }
};