/*
1567. Maximum Length of Subarray With Positive Product

Medium
Companies	Arcesium
Related Topics	Greedy

Test Cases:
[1,-2,-3,4]
[0,1,-2,-3,-4]
[-1,-2,-3,0,1]
[-1,2]
[1,2,3,5,-6,4,0,10]

Runtime: 252 ms
Memory Usage: 58.1 MB
Your runtime beats 90.86 % of cpp submissions.
Your memory usage beats 49.88 % of cpp submissions.
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // Dynamic Programming 
        int p=0, n=0, mx=0;
        for( int i=0; i<nums.size(); i++){
            if(0<nums[i]){
                p++;
                if(0<n) n++;
            }else if(nums[i]<0){
                int t=n;
                n=p+1;
                if(0<t) p=t+1;
                else    p=0;// n==0
            }else{
                p=0;
                n=0;
            }
            mx=p<mx?mx:p;
        }
        return mx;
    }
};