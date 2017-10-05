
/*

Leetcode 31. Next Permutation

Runtime: 13 ms
You are here! 
Your runtime beats 33.94 % of cpp submissions.

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // O(n*lg(n)) time, average O(n) time
        int max=*nums.rbegin(), min=*nums.rbegin(), i=nums.size(), j=nums.size(), k, nxt, temp;
        while( --i!=-1 ){
            if( nums[i]<max ){                
                break;
            }else{
                max = nums[i];
            }            
        }        
        
        if(i==-1){
            sort(nums.begin(), nums.end());
            return ;
        }
        
        while( --j!=i ){ // find the fisrt element larger than nums[i]
            if( nums[i]<nums[j] ){
                nxt = j;
                break;
            }            
        }
                    
        k=j;
        while( --j!=i ){ // find the smallest element larger than nums[i]
            if( nums[j]<nums[nxt] && nums[i]<nums[j] ){
                nxt = k;
            }
        }
        
        temp = nums[i] ;
        nums[i] = nums[k] ;
        nums[k] = temp;
        
        sort( nums.begin()+i+1, nums.end());
        return ; 
    }
};
