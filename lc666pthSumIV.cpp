
/*
Leetcode 666. Path Sum IV

Companies 
Alibaba
Related Topics 
Tree 
Similar Questions 
Path SumPath Sum II, Binary Tree Maximum Path Sum, Path Sum III

Next challenges: Binary Tree Maximum Path Sum, Path Sum III

Test Cases:
[113,213]
[113,215,221]

Your runtime beats 42.99 % of cpp submissions.

*/


class Solution {
public:
    int pathSum(vector<int>& nums) {
        // Given a list of ascending three-digits integers representing a binary with the depth smaller than 5.
        if(nums.size()<1)   return 0;
        int sum=0, d=nums.back()/100;
        
        unordered_map<int,int> um;
        vector<unordered_map<int,int>> tr(d+1, um);
        
        for(int i=0; i<nums.size(); i++)    tr[nums[i]/100].emplace(nums[i]/10%10,nums[i]%10);
        
        dfs(1, 1, nums[0]%10, sum, tr);
        
        return sum;
    }
    
    void dfs(int d, int p, int t, int& sum, vector<unordered_map<int,int>>& tr){
        // depth, position, valud of path (containing this node), total sum, tree 
        // cout<<d<<","<<p<<":"<<t<<" ";
        if(d+1<tr.size()){
            unordered_map<int,int>::iterator usi=tr[d+1].find((p<<1)-1);
            if(usi!=tr[d].end()){
                dfs(d+1, (p<<1)-1, t+usi->second, sum, tr);
                usi=tr[d+1].find(p<<1);
                if(usi!=tr[d].end())    dfs(d+1, p<<1, t+usi->second, sum, tr);
            }else{
                usi=tr[d+1].find(p<<1);
                if(usi!=tr[d].end())    dfs(d+1, p<<1, t+usi->second, sum, tr);
                else    sum+=t;
            }
        }else{
            sum+=t;
        }
        
        return ;
    }
};
