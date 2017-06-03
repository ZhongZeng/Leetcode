
/*
Leetcode 46. Permutations

You are here! 
Your runtime beats 17.87 % of cpp submissions.	16 ms
Your runtime beats 31.85 % of cpp submissions.	13 ms

Tag: Backtracking
Similar Problems: (M) Next Permutation (M) Permutations II (M) Permutation Sequence (M) Combinations
Next challenges: (M) Next Permutation(M) Permutations II(M) Permutation Sequence(M) Combinations

*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> vn;
        vn.push_back({nums[0]});
        vector<int> v;
        int n;
        for(int i=1; i!=nums.size(); i++){
            n=vn.size();
            for(int j=0; j!=n; j++){
                vn[j].push_back(nums[i]);
                for(int k=0; k!=i; k++){
                    v=vn[j];
                    v[i]=v[k];
                    v[k]=nums[i];
                    vn.push_back(v);
                }
            }
        }
        
        return vn;
    }
};