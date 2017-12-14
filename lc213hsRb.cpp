

/*
Leetcode 213. House Robber II

Related Topics 
Dynamic Programming 
Similar Questions 
House Robber, Paint House, Paint Fence, House Robber III, 
Non-negative Integers without Consecutive Ones, Coin Path 

Next challenges: Paint House, Paint Fence, House Robber III, 
Non-negative Integers without Consecutive Ones, Coin Path

Test Cases:
[]
[2]
[1,2]
[3,4,2,3,9,1]
[1]
[1,2,1,1]

Runtime: 0 ms
Your runtime beats 41.69 % of cpp submissions.


*/


class Solution {
public:
    int rob(vector<int>& nums) {
        // the best solution either contain nums[0] or not 
        if(nums.size()<1)   return 0;
        if(nums.size()<2)   return nums[0];
        int r1=robber(nums,0,nums.size()-1), r2=robber(nums,1,nums.size());
        return r1<r2?r2:r1;
    }
    
protected:
    int robber(vector<int>& nums, int st, int ed){ // st<ed, [st,ed)
        int mxt=nums[st], mxl=0, tmp;// mxt including this, mxl excluding this
        for(int i=st+1; i<ed; i++){
            tmp=mxt;
            mxt=mxl+nums[i]<mxt?mxt:mxl+nums[i];
            mxl=tmp;
        }
        //cout<<mxt<<endl;
        return mxt;
    }
};
