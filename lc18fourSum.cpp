

/*
Leetcode 18. 4Sum


Tags: Array Hash Table Two Pointers
Similar Problems: (E) Two Sum (M) 3Sum (M) 4Sum II
Next challenges: (M) 4Sum II

You are here! 
Your runtime beats 36.53 % of cpp submissions.	Runtime: 39 ms
Your runtime beats 32.16 % of cpp submissions.	Runtime: 42 ms

Amazing: successful at the second attempt; the first attempt failed at [] 0
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		// my solution to this question is similar to my solution to 3sum
		// O(n^3) time, O(1) space
        if(nums.size()<4){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> vv;
        int c,d,s;
        for(int a=0; a!=nums.size()-3; a++){
            if(a==0 || nums[a-1]!=nums[a]){
                for(int b=a+1; b!=nums.size()-2; b++){
                    if(b==a+1 || nums[b-1]!=nums[b]){
                        c=b+1;
                        d=nums.size()-1;
                        while(c!=d){
                            s=nums[a]+nums[b]+nums[c]+nums[d];
                            if(s<target){
                                do{
                                    c++;
                                }while(nums[c-1]==nums[c] && c!=d);
                            }else if(target<s){
                                do{
                                    d--;
                                }while(nums[d]==nums[d+1] && c!=d);
                            }else{
                                vv.push_back({nums[a],nums[b],nums[c],nums[d]});
                                do{
                                    c++;
                                }while(nums[c-1]==nums[c] && c!=d);
                            }
                        }
                    }
                }
            }
        }
        
        return vv;
    }
};