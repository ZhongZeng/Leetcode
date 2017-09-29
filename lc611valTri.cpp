
/*
Leetcode 611. Valid Triangle Number

Related Topics 
Array 
Similar Questions 
3Sum Smaller 

Test Cases:
[2,2,3,4]
[3,4,2,2]

Runtime: 16 ms

You are here! 
Your runtime beats 63.84 % of cpp submissions.

*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // O(n^2) time, Two-Pointer Approach 
        sort(nums.begin(), nums.end());        
        if( nums.size()<3 ) return 0; 
        int j, k, n=0; 
        
        for( int i=nums.size()-1; i!=1; i-- ){
            j=0;
            k=i-1;
            while( j<k ){
                // cout<< nums[j] <<' '<<nums[k]<<' '<<nums[i]<<endl; 
                if( nums[i]<nums[j]+nums[k] ){
                    n +=  k-j; 
                    k--;                                        
                }else{
                    j++ ; 
                }
            }            
        }
                
        return n;
    }
};

