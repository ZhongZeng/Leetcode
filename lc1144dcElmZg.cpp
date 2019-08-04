/*
Ranking of Weekly Contest 148  
Rank	Name	Score	Finish Time 	Q1 (4)	Q2 (5)	Q3 (6)	Q4 (7)
647 / 4069	zhongzeng 	15	1:38:00	 0:14:36  1	 0:50:10  1	 1:28:00	

1144. Decrease Elements To Make Array Zigzag

Companies	Google
Related Topics	Array

Runtime: 0 ms
Memory Usage: 8.7 MB

Test Case:
[4,4,3]
*/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        // O(n) time
        // 2 options, zig zag peak at index 0 or 1. Should only decrease bottom but not peak positions. 
        int rt1=countDecreases(nums, 0), rt2=countDecreases(nums, 1);
        return rt1<rt2?rt1:rt2;
    }
    
protected:
    int countDecreases(vector<int>& nums, int b){
        int rt=0;
        for( int i=b; i<nums.size(); i+=2 ){
            int t1=0, t2=0;
            if(0<i&&nums[i-1]<=nums[i]) t1=nums[i]-nums[i-1]+1;
            if(i+1<nums.size()&&nums[i]>=nums[i+1])  t2=nums[i]-nums[i+1]+1;
            rt+=t1<t2?t2:t1;
        }
        return rt;
    }
};