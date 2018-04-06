
/*
Leetcode 325. Maximum Size Subarray Sum Equals k

Companies 
Facebook, Palantir 
Related Topics 
Hash Table 
Similar Questions 
Minimum Size Subarray Sum, Range Sum Query - Immutable, 
Contiguous Array, Subarray Product Less Than K

Next challenges: Fraction to Recurring Decimal, 
Longest Substring with At Most K Distinct Characters, Number of Distinct Islands II

Test Case:
[1,-1,5,-2,3]
3

Runtime: 33 ms
Your runtime beats 74.08 % of cpp submissions.

*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // hash table, O(n); similar to leetcode 560. Subarray Sum Equals K
        int pr=0, len=0;
        unordered_map<int,int> um;// first=sum of [0,second]
        unordered_map<int,int>::iterator umi;
        um.emplace(0,-1);
        
        for(int i=0; i<nums.size(); i++){
            pr+=nums[i];
            if(um.find(pr)==um.end())   um.emplace(pr,i);

            umi=um.find(pr-k);
            if(umi!=um.end())   len=len<i-umi->second?i-umi->second:len;
        }
        
        return len;
    }
};
