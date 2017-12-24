

/*
Leetcode 747. Largest Number Greater Than Twice of Others

Test Cases:
[0,0,0,1]
[3, 6, 1, 0]
[1, 2, 3, 4]

Runtime: 12 ms

*/




class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()<2)   return 0;
        int mx, my, t, lc;
        if(nums[0]<nums[1]){
            mx=nums[1];
            my=nums[0];
            lc=1;
        }else{
            mx=nums[0];
            my=nums[1];
            lc=0;
        }
        
        
        for(int i=2; i<nums.size(); i++){
            if(mx<nums[i]){
                t=mx;
                mx=nums[i];
                lc=i;
                my=t;
            }else if(my<nums[i]){
                my=nums[i];
            }
        }
        
        return mx<my<<1?-1:lc;;
    }
};

/*
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx=nums[0], lc=0;
        for(int i=1; i<nums.size(); i++){
            if(mx<nums[i]){
                mx=nums[i];
                lc=i;
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(i!=lc&&mx<nums[i]*2) return -1;
        }
        
        return lc;
    }
};
*/