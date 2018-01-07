
/*

Leetcode 128. Longest Consecutive Sequence

Runtime: 13 ms
Your runtime beats 16.22 % of cpp submissions.

Related Topics 
Array, Union Find
Similar Questions 
Binary Tree Longest Consecutive Sequence

Next challenges: Binary Tree Longest Consecutive Sequence

Test Cases:
[100,4,200,1,3,2]
[100,200,1,3,2,4]
[100,200,1,3,2,4,4]

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // O(n*lg(n)) sort is trival 
        if(nums.size()<1)   return 0;
        
        int i, s, e, mx=0;
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator umi, umj, umt;
        for(i=0; i<nums.size(); i++){
            um.emplace(nums[i],nums[i]);
        }
        
        // quick-union: O(n) time; every element can be visited at most twice
        for(int i=0; i<nums.size(); i++){
            umj=um.find(nums[i]-1);
            if(umj!=um.end())   um.find(nums[i])->second=nums[i]-1;
        }
        
        for(int i=0; i<nums.size(); i++){
            umi=um.find(nums[i]);
            umj=umi;
            while(umj->first!=umj->second){
                umt=umj;
                umj=um.find(umj->second);
                umt->second=umt->first;
            }  
            umi->second=umj->first;
        }
        
        // travse all elements: O(n) time
        for(umi=um.begin(); umi!=um.end(); umi++){
            if(mx<umi->first-umi->second){
                s=umi->second;
                e=umi->first;
                mx=e-s;
            }
        }
        
        return mx+1;
    }
};
