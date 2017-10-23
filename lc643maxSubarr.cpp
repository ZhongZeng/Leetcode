
/*
Leetcode 643. Maximum Average Subarray I

Related Topics 
Array 
Similar Questions 
Maximum Average Subarray II 

Next challenges: Maximum Average Subarray II

Test Case:
[1,12,-5,-6,50,3]
4

Runtime: 189 ms
You are here! 
Your runtime beats 46.02 % of cpp submissions.

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // 
        int sum=0, i=-1, mx;
        while( ++i!=k ){
            sum += nums[i];
        }
        mx = sum;
                
        i--;
        while( ++i!=nums.size() ){
            sum -= nums[i-k];
            sum += nums[i];
            mx = mx<sum ? sum : mx;
        }                
        
        return mx*1.0/k;
    }
};
