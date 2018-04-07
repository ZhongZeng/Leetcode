

/*
Leetcode 47. Permutations II

Companies 
Microsoft, Linkedin
Related Topics 
Backtracking 
Similar Questions 
Next Permutation, Permutations, Palindrome Permutation II

Next challenges: Palindrome Permutation II

Test Cases:
[1,1,2]
[1,2,3,4]
[2,2,1,1]

Runtime: 27 ms
Your runtime beats 63.26 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // backtrack, DFS
        vector<vector<int>> rt;
        rt.push_back(nums);
        
        backTrack( nums, rt, 0);
        
        return rt;
    }
    
    void backTrack(vector<int>& nums, vector<vector<int>>& rt, int i){
        if(i+1<nums.size()) backTrack( nums, rt, i+1); // including DFS from itself 
        unordered_set<int> us;
        us.emplace(nums[i]);
        for(int j=i+1; j<nums.size(); j++){//  unique # @ ith position
            unordered_set<int>::iterator usi=us.find(nums[j]);
            if(usi==us.end()){// similar to permutation but exclude duplicate
                us.emplace(nums[j]);
                int t=nums[i];
                nums[i]=nums[j];
                nums[j]=t;
                rt.push_back(nums);
                backTrack( nums, rt, i+1);
                nums[j]=nums[i];
                nums[i]=t;                    
            }
        }
        return ;
    }
};
