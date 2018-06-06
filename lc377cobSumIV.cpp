
/*
Leetcode 377. Combination Sum IV


Companies 
Google, Facebook, Snapchat 
Related Topics 
Dynamic Programming
Similar Questions 
Combination Sum

Next challenges: Longest Palindromic Substring, Max Sum of Rectangle No Larger Than K, 
Best Time to Buy and Sell Stock with Transaction Fee

Test Cases:
[1,2,3]
4
[1,2,3]
32

Runtime: 4 ms
Your runtime beats 27.57 % of cpp submissions.

*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // post-order DFS+DP; similar to combination sum, just adding 1 more condition
        // all positive numbers and no duplicates
        int rt=0;
		unordered_map<int,int> um;// target, sum 
        unordered_map<int,int>::iterator umi;
		
        dfs( target, nums, um);
        
		umi=um.find(target);
		
        return umi!=um.end()?umi->second:0;
    }
    
    int dfs( int t, vector<int>& nums, unordered_map<int,int>& um){// t guranteed not in um 
        int sum=0;
		unordered_map<int,int>::iterator umi;
		
        for( int j=0; j<nums.size(); j++){
            t-=nums[j];
            
            if(0<t){
				umi=um.find(t);
				if(umi!=um.end())   sum+=umi->second;
				else	sum+=dfs( t, nums, um);
			}else if(t==0){
				sum++;
			}
            
            t+=nums[j];
        }
        
		um.emplace(t, sum);
		
        return sum;
    }
};
