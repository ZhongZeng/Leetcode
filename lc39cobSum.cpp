
/*
Leetcode 39. Combination Sum

Companies 
Uber, Snapchat 
Related Topics 
Array, Backtracking
Similar Questions 
Letter Combinations of a Phone Number, Combination Sum II, 
Combinations, Combination Sum III, Factor Combinations, Combination Sum IV

Test Cases:
[2,3,6,7]
7
[8,7,4,3]
11

Next challenges: Combination Sum II, Combination Sum III, Factor Combinations, Combination Sum IV

Runtime: 23 ms
Your runtime beats 27.06 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // similer to Permutation&Combination; DFS
        // positive non-duplicate numbers 
        vector<vector<int>> rt;
        vector<int> v;
        
        dfs( 0, target, v, candidates, rt);
        
        return rt;
    }
    
    void dfs( int i, int t, vector<int>& v, vector<int>& candidates, vector<vector<int>>& rt){
        
        for( int j=i; j<candidates.size(); j++ ){
            t-=candidates[j];
            v.push_back(candidates[j]);
            //for(auto e:v)   cout<<e<<" ";   cout<<endl;
            
            if(0<t){
                dfs( j, t, v, candidates, rt);
                t+=candidates[j];
                v.pop_back();
            }else if(t<0){
                t+=candidates[j];
                v.pop_back();
            }else{// t==0
                rt.push_back(v);
                
                t+=candidates[j];
                v.pop_back();
            }
        }
        
        return ;
    }
};
