

/*
Leetcode 287. Find the Duplicate Number

Related Topics 
Array, Two Pointers, Binary Search 
Similar Questions 
First Missing Positive, Single Number, Linked List Cycle II, Missing Number, Set Mismatch 

Next challenges: First Missing Positive, Single Number, Set Mismatch

Runtime: 13 ms
You are here! 
Your runtime beats 26.96 % of cpp submissions.

*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // binary search, (lo, hi]
        int lo=0, hi=nums[0], mid, cnt;
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            if( hi<*it ){
                hi = *it;
            }
        }
        
        while( lo!=hi-1 ){
            cnt=0;
            mid=lo+(hi-lo)/2;
            for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
                if(*it<=hi && mid<*it)   cnt++;
            }
            if( hi-mid<cnt ){
                lo = mid;
            }else{
                hi = mid;
            }            
        }
        
        return hi;
    }
};
