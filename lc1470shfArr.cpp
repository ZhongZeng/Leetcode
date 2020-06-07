/*
1470. Shuffle the Array

Easy
Companies	Microsoft
Related Topics	Array

Weekly Contest 192

Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
2261 / 13805	zhongzeng 	12	0:34:33	 0:06:26	 0:24:59	 0:34:33

Test Cases:
[2,5,1,3,4,7]
3
[1,2,3,4,4,3,2,1]
4
[1,1,2,2]
2

Runtime: 8 ms
Memory Usage: 9.9 MB
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // O(n) time; nums.size()==2n
        vector<int> vc;
        for( int i=0; i<nums.size()/2; i++){
          vc.push_back(nums[i]);
          vc.push_back(nums[i+n]);
        }
        return vc;
    }
};