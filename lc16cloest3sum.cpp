
/*
Leetcode 16. 3Sum Closest

Tags: Array Two Pointers
Similar Problems: (M) 3Sum (M) 3Sum Smaller

Next challenges: (M) 3Sum Smaller

You are here! 
Your runtime beats 46.23 % of cpp submissions.
Runtime: 9 ms
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // O(n*n) time, O(1) space
        sort(nums.begin(),nums.end());
        int b,e,s,d=target-nums[0]-nums[1]-nums[2],c=nums[0]+nums[1]+nums[2];
        for(int i=0; i!=nums.size()-2; i++){
            b=i+1;
            e=nums.size()-1;
            while(b!=e){
                s=nums[i]+nums[b]+nums[e];
                if(abs(target-s)<d){
                    d=abs(target-s);
                    c=s;
                }
                if(s<target){
                    b++;
                }else if(target<s){
                    e--;
                }else{
                    return target;
                }
            }
        }
        return c;
    }
};