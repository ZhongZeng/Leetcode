
/*
491. Increasing Subsequences

Related Topics:	Depth-first Search 
Similiar Questions:	Maximum Length of Pair Chain

Test Case:
[4,6,7,7]

Runtime: 212 ms, faster than 51.29% of C++ online submissions for Increasing Subsequences.

*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // DFS, avoid duplicate
        vector<vector<int>> vv;
        vector<int> vc;
        
        dfs(vv,nums,vc,0);
        
        return vv;
    }
    
    void dfs(vector<vector<int>>& vv, vector<int>& nums, vector<int>& vc, int i){// last element in nums is nums[i-1] 
        unordered_set<int> us;
        
        for( int j=i; j<nums.size(); j++){
            if(us.find(nums[j])==us.end()){// make sure no duplicates pushed_back to vc, which means all vc in all next dfs() is unique; vc is also unique, thus vv is unique 
                us.emplace(nums[j]);
                if(vc.empty()){
                    vc.push_back(nums[j]);
                    dfs( vv, nums, vc, j+1);
                    vc.pop_back();
                }else if(vc.back()<=nums[j]){
                    vc.push_back(nums[j]);
                    vv.push_back(vc);
                    dfs( vv, nums, vc, j+1);
                    vc.pop_back();
                }
            }
        }
        
        return ;
    }
};
