
/*
Leetcode 259. 3Sum Smaller

Companies 
Google 
Related Topics 
Array, Two Pointers 
Similar Questions 
3Sum3Sum ClosestValid Triangle Number

Next challenges: Substring with Concatenation of All Words, 
Subsets II, Split Array with Equal Sum

Test Cases:
[]
0
[-2, 0, 1, 3]
2

Runtime: 9 ms
Your runtime beats 69.25 % of cpp submissions.

*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // 2-pointer, O(n*n) time
        if(nums.size()<3)   return 0;
        int sum=0, j, k;
        sort( nums.begin(), nums.end());
        
        for( int i=0; i<nums.size()-2; i++){
            j=i+1;
            k=nums.size()-1;
            
            while(j<k){
                if(nums[i]+nums[j]+nums[k]<target){
                    sum+=k-j;// unique i&j
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        return sum;
    }
};
