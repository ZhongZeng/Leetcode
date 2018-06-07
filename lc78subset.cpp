
/*
Leetcode 78. Subsets

Companies 
Facebook, Amazon, Bloomberg, Uber, Coupang 
Related Topics 
Array, Backtracking, Bit Manipulation 
Similar Questions 
Subsets IIGeneralized AbbreviationLetter Case Permutation

Test Cases:
[1,2,3]
[1,2,3,4]

Runtime: 8 ms
Your runtime beats 29.59 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // backtrack+DFS, similar to combination; distinct integers
        vector<vector<int>> rt;
		vector<int> v;
        rt.push_back(v);
        
        dfs( 0, v, nums, rt);
        
        return rt; 
    }
    
    void dfs( int i, vector<int>& v, vector<int>& nums, vector<vector<int>>& rt){
        
		for( int j=i; j<nums.size(); j++){
            v.push_back(nums[j]);
            rt.push_back(v);
            
			if(j+1<nums.size()) dfs( j+1, v, nums, rt);
            
            v.pop_back();
		}
        
        return ;
    }
};

