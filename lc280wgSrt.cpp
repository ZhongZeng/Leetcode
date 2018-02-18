
/*
Leetcode 280. Wiggle Sort

Companies 
Google
Related Topics 
Array, Sort
Similar Questions 
Sort Colors, Wiggle Sort II

Test Cases:
[3,5,2,1,6,4]
[]

Runtime: 44 ms
Your runtime beats 26.92 % of cpp submissions.

*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // greedy; if = not permitted, would be hard
        for(int i=1, t; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                t=nums[i];
                nums[i]=nums[i-1];
                nums[i-1]=t;
            }
            
            if(++i<nums.size()){
                if(nums[i-1]<nums[i]){
                    t=nums[i];
                    nums[i]=nums[i-1];
                    nums[i-1]=t;
                }                
            }else{
                break;
            }
        }
        return ;
    }
};