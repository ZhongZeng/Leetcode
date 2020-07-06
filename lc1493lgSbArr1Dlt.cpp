/*
1493. Longest Subarray of 1's After Deleting One Element
Medium
Companies	Yandex
Related Topcis	Array

Test Cases:
[1,1,0,1]
[0,1,1,1,0,1,1,0,1]
[1,1,1]
[1,1,0,0,1,1,1,0,1]
[0,0,0]

Runtime: 92 ms, faster than 84.87% of C++ online submissions for Longest Subarray of 1's After Deleting One Element.
Memory Usage: 36.7 MB, less than 25.00% of C++ online submissions for Longest Subarray of 1's After Deleting One Element.
Next challenges: Find K-th Smallest Pair Distance, Pour Wate, 
Moving Stones Until Consecutive II
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len0=0, len1=0, len_max=0, ones=0;
        for( int i=0; i<nums.size(); i++){
            if(nums[i]==1)  ones++;
            else    break;
        }
        if(ones==nums.size())   return nums.size()-1;
        
        for( int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                len1++;
            }else{
                if(len_max<len0+len1)   len_max=len0+len1;
                if(0<i&&i<nums.size()-1&&nums[i-1]==1&&nums[i+1]==1){
                    len0=len1;
                    len1=0;
                }else{
                    len0=0;
                    len1=0;
                }
            }
        }
        if(len_max<len0+len1)   len_max=len0+len1;
        return len_max;
    }
};