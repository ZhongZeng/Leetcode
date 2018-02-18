
/*
Leetcode 453. Minimum Moves to Equal Array Elements

Companies 
Indeed, Coursera 
Related Topics 
Math 
Similar Questions 
Minimum Moves to Equal Array Elements II

Next challenges: Minimum Moves to Equal Array Elements II

Test Cases:
[1,2,3]
[7,11,5,12,9,8]

Runtime: 54 ms
Your runtime beats 43.18 % of cpp submissions.

*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // incrementing n - 1 elements by 1 is equvalent to reducing 1 element by 1
        if(nums.size()<1)   return 0;
        int sum=0, mn=nums[0];
        for(int i=0; i<nums.size(); i++)    if(nums[i]<mn)  mn=nums[i];
        for(int i=0; i<nums.size(); i++)    sum+=nums[i]-mn;
        
        return sum;
    }
};


/*
// Runtime: 70 ms
// Your runtime beats 13.64 % of cpp submissions.
class Solution {
public:
    int minMoves(vector<int>& nums) {
        // incrementing n - 1 elements by 1 is equvalent to reducing 1 element by 1
        if(nums.size()<1)   return 0;
        int sum=0, mn=nums[0];
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<mn)  mn=nums[i];
            sum+=nums[i];
        }    
        
        return sum-mn*nums.size();
    }
};
*/
