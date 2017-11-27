
/*
Leetcode 376. Wiggle Subsequence

Related Topics 
Dynamic Programming Greedy 

Next challenges: Wildcard Matching, 
Range Sum Query 2D - Immutable, Longest Palindromic Subsequence

Test Cases:
[]
[0,0]
[0,0,0]
[1,7,4,9,2,5]
[1,17,5,10,13,15,10,5,16,8]
[3,3,3,2,5]
[3,3,3,2]
[1,7,4,9,2,5]
[1,1,7,4,9,2,5]

*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // DP
        if(nums.size()<2)   return nums.size();
        
        int len=nums.size(), i=0;
        while( ++i<nums.size() ){
            if(nums[i]!=nums[i-1])  break;
            else    len--;
        }
        
        bool asd=0<nums[i]-nums[i-1]?true:false;
        while(++i<nums.size()){
            if( asd ){
                if(nums[i]-nums[i-1]<0) asd=false;
                else    len--;
            }else{
                if(0<nums[i]-nums[i-1]) asd=true;                    
                else    len--;
            }            
        }
        
        return len;
    }
};

