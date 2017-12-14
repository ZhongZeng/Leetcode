

/*
Leetcode 713. Subarray Product Less Than K

Related Topics 
Array Two Pointers 
Similar Questions 
Maximum Product Subarray, Maximum Size Subarray Sum Equals k, Subarray Sum Equals K 

Next challenges: Maximum Size Subarray Sum Equals k

Test Cases:
[10,5,2,6]
100
[10,9,10,4,3,8,3,3,6,2,10,10,9,3]
19

Runtime: 142 ms
Your runtime beats 30.36 % of cpp submissions.

*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // O(n*n) time is straight forward
        // 2-pointer, DP
		// Using 2-pointer directly won't solve it, apply it with trick 
        int sum=0, i=0, j=0, ts=nums[0];// subarray [i,j]
        while(j!=nums.size()){
            if(ts<k){
                sum+=j-i+1;// all subarrays ending in j
                //cout<<nums[i]<<" "<<nums[j]<<" "<<j-i+1<<endl;
                j++;
                ts*=nums[j];
            }else{
                if(i!=j){
                    ts/=nums[i];
                    i++;                    
                }else{
                    i++;
                    j++;
                    ts=nums[i];
                }
            }
        }
        
        return sum;
    }
};
