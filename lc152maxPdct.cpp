

/*
Leetcode 152. Maximum Product Subarray

Tags: 
Array, Dynamic Programming
Similar Problems:
Maximum Subarray, House Robber, Product of Array Except Self, 
Maximum Product of Three Numbers, Subarray Product Less Than K

Next challenges: Regular Expression Matching, 
Distinct Subsequences, Guess Number Higher or Lower II

Test Cases:
[-2]
[-2,4,2,5,-4,2,4,-2,5]
[4,2,5,-4,2,4,-2,5]
[-2,0,-1]

Runtime: 3 ms
Your runtime beats 42.53 % of cpp submissions.

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // WRONG - Use the same logic from Leetcode 198 House Robber
        // O(n) time, O(1) space 
        if(nums.size()<2)   return nums[0];
        
        int mp=0, mn=0, mx=nums[0], t;// positive and negative max products
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            if(0<*it){
                if(0<mp)    mp*=*it;  
                else   mp=*it;
                if(mn<0)    mn*=*it; 
            }else if(*it<0){
                if(mn<0){
                    if(0<mp){ // mn mp
                        mx=mx<mp?mp:mx;
                        t=mn;
                        mn=*it*mp;
                        mp=*it*t;
                    }else{ // mn !mp
                        mp=*it*mn;
                        mn=*it;
                    }
                }else{
                    if(0<mp){ // !mn mp
                        mx=mx<mp?mp:mx;
                        mn=*it*mp;
                        mp=1;              
                    }else{ // 1st element
                        mx=mx<mn?mn:mx;
                        mn=*it;
                    }
                }
            }else{
                mx=mx<mp?mp:mx;
                mp=0;
                mn=0;
            }
        }
        mx=mx<mp?mp:mx;
        mx=mx<mn?mn:mx;
        return mx;
    }
};

