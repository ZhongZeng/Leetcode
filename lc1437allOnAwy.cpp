/*
1437. Check If All 1's Are at Least Length K Places Away

Medium
Companies	United Health Group
Related Topics	Array

Test Cases:
[1,0,0,0,1,0,0,1]
2
[1,0,0,1,0,1]
2

Runtime: 180 ms, faster than 49.58% of C++ online submissions for Check If All 1's Are at Least Length K Places Away.
Memory Usage: 57.6 MB, less than 73.56% of C++ online submissions for Check If All 1's Are at Least Length K Places Away.
Next challenges: Pour Water, Shift 2D Grid, 
Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // Easy; follow-up: remove least numbers of 1 to achieve that, Greedy
        
        for( int i=0, pre=-k-1; i<nums.size(); i++){
            if(nums[i]==1){
                if(i-pre<=k)    return false;
                pre=i;
            }
        }
        
        return true;
    }
};