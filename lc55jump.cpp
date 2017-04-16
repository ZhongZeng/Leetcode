

/*
Leetcode 55. Jump Game
You are here! 
Your runtime beats 21.34% of cpp submissions. 16 ms
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxe=0;
        for(int it=0; it!=nums.size(); it++){
            // cout<<nums[it]<<endl;
            if(maxe<it){
                return false;
            }
            
            if(maxe<nums[it]+it){
                maxe=nums[it]+it;
            }
        }
        
        return true;
    }
};

