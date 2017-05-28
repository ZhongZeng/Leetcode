


/*
Leetcode 34. Search for a Range

Tags: Binary Search, Array
Similar Problems (E) First Bad Version
Next challenges: (E) Majority Element(M) Game of Life(E) K-diff Pairs in an Array

Runtime: 9 ms
You are here! 
Your runtime beats 47.27 % of cpp submissions.

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int b=-1, e=nums.size(), mid, bi=-1, ei=-1;
        
        if(nums.size()==0){
            return {-1,-1};
        }else if(target<*nums.begin()||*nums.rbegin()<target){
            return {-1,-1};
        }
        /* Find the range where b<target && mid=target && target<e*/
        while(b!=e-1){
            mid=(b+e)/2;
            // cout<<nums[mid]<<endl;
            if(nums[mid]<target){
                b=mid;
            }else if(target<nums[mid]){
                e=mid;
            }else{
                bi=mid;
                ei=mid;
                break;
            }
        }
        if(bi==-1){
            return {-1,-1};
        }
        
        // nums[b]<target && target<nums[e] == 1
        while(b!=bi-1){
            mid = (b+bi)/2;
            // cout<<nums[mid]<<endl;
            if(nums[mid]==target){
                bi=mid;
            }else{
                b=mid;
            }
        }
        
        while(ei!=e-1){
            mid = (e+ei)/2;
            // cout<<nums[mid]<<endl;
            if(nums[mid]==target){
                ei=mid;
            }else{
                e=mid;
            }
        }
        
        return {bi,ei};
    }
};