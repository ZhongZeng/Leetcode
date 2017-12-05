
/*
Leetcode 540. Single Element in a Sorted Array

Runtime: 6 ms
Your runtime beats 15.63 % of cpp submissions.

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // if not sorted, use bit manipulation ^
        // it's sorted, so binary search
        if(nums[0]!=nums[1])    return nums[0];
        int b=1, e=nums.size(), mid;
        while(b<e-1){
            mid=b+(e-b)/2;
            if(mid%2!=0){
                if(nums[mid]!=nums[mid-1])  e=mid;
                else    b=mid;
            }else{
                if(nums[mid]!=nums[mid-1])  b=mid;
                else    e=mid;
            }
        }
        
        return nums[b];
    }
};
