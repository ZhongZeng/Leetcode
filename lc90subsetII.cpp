
/*
Leetcode 90. Subsets II

Companies 
Facebook 
Related Topics 
Array, Backtracking 
Similar Questions 
Subsets

Test Cases:
[1,2,2]

Runtime: 12 ms
Your runtime beats 29.35 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // DFS+backtracking, similair to combination 
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi;
        vector<vector<int>> rt;
        vector<int> v;
        rt.push_back(v);
        
        for( int i=0; i<nums.size(); i++){
            umi=um.find(nums[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(nums[i],1);
        }
        
        dfs( um.begin(), v, um, rt);
        
        return rt;
    }
    
    void dfs( unordered_map<int,int>::iterator umi, vector<int>& v, unordered_map<int,int>& um, vector<vector<int>>& rt){
        int i, j;
        unordered_map<int,int>::iterator umj, umt;
        
        for( umj=umi; umj!=um.end(); umj++){
            for( i=0; i<umj->second; i++){
                v.push_back(umj->first);
                rt.push_back(v);
                
                //for(auto e:v)   cout<<e<<" ";   cout<<endl;
                umt=umj;
                if(++umt!=um.end()) dfs( umt, v, um, rt);
            }
            
            for( j=0; j<i; j++) v.pop_back();
        }
        
        return ;
    }
};