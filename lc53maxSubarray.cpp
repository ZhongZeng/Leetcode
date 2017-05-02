

/*
Leetcode 53. Maximum Subarray
Tags: Array Dynamic Programming Divide and Conquer
Similar Problems: (E) Best Time to Buy and Sell Stock (M) Maximum Product Subarray

You are here! 
Your runtime beats 29.78 % of cpp submissions. 12 ms

[-2,1,-3,4,-1,2,1,-5,4]
[-2,1]
[1]
[-1] //187 / 202 test cases passed.
[-1,0,-2] 186 / 202 test cases passed.

*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumc=nums[0], summ=nums[0];
        for(vector<int>::iterator it=++nums.begin(); it!=nums.end(); it++){
            if(sumc<0){
                if(sumc<*it){
                   sumc = *it;
                   summ = max(summ, sumc);
                }
            }else{//0<=sumc
                if(0<*it){
                    sumc += *it;
                    summ = max(summ, sumc);
                }else{// *it<=0
                    sumc += *it;
                }
            }
        }
        return max(sumc, summ);
    }
};

