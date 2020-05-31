/*
1464. Maximum Product of Two Elements in an Array

Ranking of Weekly Contest 191  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
1560 / 13283	zhongzeng 	12	0:41:48	 0:05:18	 0:15:22  1	 0:36:48	

Companies	Samsung
Related Topics	Array

Test Cases:
[3,4,5,2]
[1,5,4,5]
[3,7]

Runtime: 16 ms	Your runtime beats 50.00 % of cpp submissions.
Memory Usage: 9.9 MB
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // O(n) time, nums[i] in [1,1000]
        int mx1=1, mx2=1;
        for( int i=0; i<nums.size(); i++){
            if(mx1<nums[i]){
                mx2=mx1;
                mx1=nums[i];
            }else if(mx2<nums[i]){
                mx2=nums[i];
            }
        }
        return (mx1-1)*(mx2-1);
    }
};