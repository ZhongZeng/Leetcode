

/*
Leetcode 334. Increasing Triplet Subsequence

Similar Questions 
Longest Increasing Subsequence 

Next challenges: Convert Sorted Array to Binary Search Tree, 
Strobogrammatic Number III, Number of Segments in a String

Runtime: 9 ms
You are here! 
Your runtime beats 5.49 % of cpp submissions.

Runtime: 6 ms
You are here! 
Your runtime beats 24.89 % of cpp submissions.

Test Cases:
[1,2,3,4,5]
[2,6,3,9,5]
[9,5,6,2,3]
[5,1,5,5,2,5,4]

*/


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        /* You only need to return true or false not find the subsequence.
        DP*/
        if(nums.size()<3)   return false;
        vector<int> v1 = { nums[0] } , v2; 
        int i=0, a1=nums[0] , a2, b1; 
        bool bi=false;
        while( ++i!=nums.size() ){
            if( a1<nums[i] ){
                a2 = nums[i];
                break;
            }else{
                a1=nums[i];
            }
        }
        //cout<<i<<endl;
        
        // a1<a2, loc(a1)<loc(a2), if any a2
        // b1<a2, loc(a2)<loc(b1), if any b1
        i--;
        while( ++i!=nums.size() ){
            if( bi ){
                if( nums[i]<=b1 ){
                    b1 = nums[i];
                }else if( nums[i]<=a2 ){
                    a1 = b1;
                    a2 = nums[i]; 
                    bi = false; 
                }else{
                    return true;
                }
                //cout<<a1<<' '<<a2<<' '<<b1<<endl;
            }else{
                if( nums[i]<=a1){
                    b1=nums[i];
                    bi = true;
                }else if( nums[i]<a2 ){
                    a2 = nums[i];                    
                }else if( a2 < nums[i]){
                    return true;                    
                } 
                //cout<<a1<<' '<<a2<<endl;
            }         
        }        
        // cout<<endl;
        
        return false;
    }
    
};