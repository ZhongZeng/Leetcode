
/*

Leetcode 169. Majority Element

Tags: Array, Divide and Conquer, Bit Manipulation
Similar Problems: (M) Majority Element II
Next challenges: (M) Majority Element II

You are here! 
Your runtime beats 12.06 % of cpp submissions.
29 ms

*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		// this solution is inspired by others' solution
		// O(nlog(n)) time, O(1) space
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main(){
	vector<int> vec = {1, 2, 3, 4, 5};
	Solution s;
	s.majorityElement(vec);
}