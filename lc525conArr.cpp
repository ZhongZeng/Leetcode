
/*
Leetcode 525. Contiguous Array

Related Topics 
Hash Table 
Similar Questions 
Maximum Size Subarray Sum Equals k 

Next challenges: Maximum Size Subarray Sum Equals k

Test Cases:
[0,1]
[0,1,0]

Runtime: 132 ms
You are here! 
Your runtime beats 79.01 % of cpp submissions.

I got hint from the label hash_table and titles of solutions (0-1 diff).
AC at 1st attempt

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // hash_table< 0-1 diff, position>
        int i=0, dif=0, ml=0;
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator umi;
        um.emplace(0,-1);
        for( int i=0; i!=nums.size(); i++ ){
            if( nums[i]!=0 ){
                dif++;
            }else{
                dif--;
            }
            umi=um.find(dif);
            if( umi!=um.end() ){
                ml = ml<i-umi->second ? i-umi->second : ml;
            }else{
                um.emplace(dif, i);
            }
        }
        
        return ml;
    }
};
