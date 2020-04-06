/*
1403. Minimum Subsequence in Non-Increasing Order

Weekly Contest 183
Rank	Name	Score	Finish Time 	Q1 (4)	Q2 (4)	Q3 (6)	Q4 (7)
3841 / 12542	zhongzeng 	8	0:38:14	 0:08:21  1	 0:28:14  1	

Company	mercari
Related Topics	Greedy, Sort

Test Cases:
[4,3,10,9,8]
[4,4,7,6,7]
[6]

Runtime: 16 ms	Your runtime beats 84.34 % of cpp submissions.
Memory Usage: 10.5 MB

https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/discuss/566099/C%2B%2B-Sort
*/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        // O(n*log(n)) time; nums[i] in [1,100]
        int sum_tot=0, sum_sub=0;
        vector<int> sub;
        for( int i=0; i<nums.size(); i++)   sum_tot+=nums[i];
        sort( nums.begin(), nums.end());
        for( int i=nums.size()-1; -1<i; i--){
            sum_sub+=nums[i];
            sub.push_back(nums[i]);
            if(sum_tot-sum_sub<sum_sub) return sub;
        }
        return sub;
    }
};