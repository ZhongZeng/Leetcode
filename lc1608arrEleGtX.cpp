/*
1608. Special Array With X Elements Greater Than or Equal X

Companies:	Google
Related Topics:	Array

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 8.4 MB	Your memory usage beats 47.04 % of cpp submissions.
Runtime: 8 ms	Your runtime beats 9.69 % of cpp submissions.
Memory Usage: 8.6 MB	Your memory usage beats 8.26 % of cpp submissions.
*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        // O(n) time, O(1) space 
        // It can be proven that if nums is special, the value for x is unique.
        if(nums.size()<1)   return -1;
        sort(nums.begin(), nums.end());
        
        if(nums.size()<=nums[0])    return nums.size();
        for( int i=1; i<nums.size(); i++){
            if(nums[i-1]<nums[i]){
                int x=nums.size()-i;
                if(nums[i-1]<x&&x<=nums[i])
                    return x;
            }
        }
        
        return -1;
    }
};