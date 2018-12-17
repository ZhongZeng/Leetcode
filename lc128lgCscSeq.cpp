
/*

Leetcode 128. Longest Consecutive Sequence



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

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Longest Consecutive Sequence.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		// O(n) time, assuming no duplicates in nums 
        unordered_map<int,int> us;// key, visited 
		unordered_map<int,int>::iterator usi, usj;
		int mx=0, mt;
		
		for( int i=0; i<nums.size(); i++)	us.emplace(nums[i],0);
		
		for( usi=us.begin(); usi!=us.end(); usi++){
			if(usi->second==0){
				mt=1;
				for( usj=us.find(1+usi->first); usj!=us.end(); mt++){
					usj->second=1;// usj->second==0 guranteed 
					usj=us.find(1+usj->first);
				}
				for( usj=us.find(-1+usi->first); usj!=us.end(); mt++){
					usj->second=1;
					usj=us.find(-1+usj->first);
				}
				if(mx<mt)	mx=mt;
			}
		}
		
		return mx;
    }
};

// Runtime: 13 ms	Your runtime beats 16.22 % of cpp submissions.
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
