
/*
Leetcode 136. Single Number

Related Topics 
Hash Table Bit Manipulation 
Similar Questions 
Single Number II, Single Number III, Missing Number, 
Find the Duplicate Number, Find the Difference 

Runtime: 19 ms
You are here! 
Your runtime beats 17.93 % of cpp submissions.

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>::iterator it=nums.begin();
        int n=*it;
        while( ++it!=nums.end() ){
            n = *it ^ n;
        }
        
        return n;
    }
};
