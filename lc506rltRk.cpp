

/*
Leetcode 506. Relative Ranks

Next challenges: Find the Celebrity, 
Matchsticks to Square, Boundary of Binary Tree

Test Case:
[5,4,3,2,1]

Runtime: 16 ms
Your runtime beats 25.60 % of cpp submissions.

*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        // sort; O(n*lg(n)) time, O(n) space
        int rk;
        vector<string> vs;
        vector<int> vc=nums;
        unordered_map<int,int> um;
        sort(vc.begin(),vc.end());
        reverse(vc.begin(),vc.end());
        
        for(int i=0; i!=vc.size(); i++)
            um.emplace(vc[i], i);
        
        for(int i=0; i!=nums.size(); i++){
            rk=um.find(nums[i])->second;
            switch(rk){
                case 0: vs.push_back("Gold Medal");
                    continue;
                case 1: vs.push_back("Silver Medal");
                    continue;
                case 2: vs.push_back("Bronze Medal");
                    continue;
                default: vs.push_back(to_string(rk+1));
                    continue;
            }
        }
        
        return vs;
    }
    
};
