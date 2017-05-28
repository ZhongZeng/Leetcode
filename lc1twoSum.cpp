

/*
Leetcode: 1. Two Sum

Tags: Array Hash Table
Similar Problems: (M) 3Sum (M) 4Sum (E) Two Sum II - Input array is sorted 
(E) Two Sum III - Data structure design (M) Subarray Sum Equals K
Next challenges: (M) 4Sum(E) Two Sum III - Data structure design(M) Subarray Sum Equals K


You are here! 
Your runtime beats 78.24 % of cpp submissions.
Runtime: 6 ms

Test cases:
[3,3]

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator t;
        for(int it=0;it!=nums.size();it++){
            t=m.find(target-nums[it]);
            if(t!=m.end()){
                return {t->second,it};
            }else{
                m.emplace(nums[it],it);
            }
        }
        
    }
};

/* // Wrong Solution:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums1(nums);
        sort(nums.begin(),nums.end());
        int b=0,e=nums.size()-1,s;
        
        while(b!=e){
            s=nums[b]+nums[e];
            if(s<target){
                b++;
            }else if(target<s){
                e--;
            }else{
                break;
            }
        }
        //int ib=find(nums1.begin(),nums1.end(),nums[b])-nums1.begin();
        // int ie=find(nums1.begin(),nums1.end(),nums[e])-nums1.begin();
        // return {ib,ie};
        return {find(nums1.begin(),nums1.end(),nums[b])-nums1.begin(),find(nums1.begin(),nums1.end(),nums[e])-nums1.begin()};
        
    }
};
*/