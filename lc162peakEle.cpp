
/*

Leetcode 162. Find Peak Element

Related Topics 
Array Binary Search 

Next challenges: Smallest Rectangle Enclosing Black Pixels, 
Max Sum of Rectangle No Larger Than K, Longest Continuous Increasing Subsequence

Test Cases:
[1,2,3,1]
[1,3,5,6,2,3,1]
[1,2,3]
[1]

Runtime: 3 ms
You are here! 
Your runtime beats 70.99 % of cpp submissions.

*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<2)    return 0;
        if(nums[1]<nums[0]) return 0;
        for(int i=1; i!=nums.size()-1; i++){
            if(nums[i-1]<nums[i] && nums[i+1]<nums[i]){
                return i;                
            }                        
        }   
        if(nums[nums.size()-2]<*nums.rbegin()) return nums.size()-1;
        return 0;
    }
};
