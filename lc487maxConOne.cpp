
/*
Leetcode 487. Max Consecutive Ones II

Companies 
Google 
Related Topics 
Two Pointers
Similar Questions 
Max Consecutive Ones

Test Cases:
[1]
[1,1]
[1,0,1,1,0,1]
[1,0,1,1,0,0,1,1,1,1,1]
[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0]

Runtime: 40 ms
Your runtime beats 52.59 % of cpp submissions.

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i, j, mx=0, t=0;
        for( i=0; nums[i]!=1; i++){}
        j=i;
        
        while(j<nums.size()){
            if(nums[j]!=0){
                j++;
            }else{
                mx=mx<t+j-i+1?t+j-i+1:mx;
                
                if(j+1<nums.size()&&nums[j+1]!=0)   t=j-i; // flip 0 possible 
                else    t=0; // flip 0 impossible 
                
                while(++j<nums.size()&&nums[j]!=1){}
                i=j;
            }
        }
        mx=mx<t+j-i+1?t+j-i+1:mx;
        if(i==0&&j==nums.size())    return nums.size();// [1,...,1]
        
        return mx;
    }
};
