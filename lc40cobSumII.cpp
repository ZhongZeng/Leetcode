
/*
Leetcode 40. Combination Sum II

Companies 
Snapchat
Related Topics 
Array, Backtracking 
Similar Questions 
Combination Sum

Next challenges: Median of Two Sorted Arrays, N-Queens II, Maximum Average Subarray II

Test Cases:
[10,1,2,7,6,1,5]
8
[2,5,2,1,2]
5

Runtime: 22 ms
Your runtime beats 18.69 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // DFS, similar to combination&permutation
        // positive candidates&target; Each number used once 
        vector<int> v;
        vector<vector<int>> rt;
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator umi;
        
        for( int i=0; i<candidates.size(); i++){
            umi=um.find(candidates[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace( candidates[i], 1);
        }
        
        dfs( um.begin(), target, v, um, rt);
        
        return rt;
    }
    
    void dfs( unordered_map<int,int>::iterator umi, int t, vector<int>& v, unordered_map<int,int> um, vector<vector<int>>& rt){
        int i, j;
        
        for( unordered_map<int,int>::iterator umj=umi, umt; umj!=um.end(); umj++){
            for( i=0; i<umj->second; i++){
                t-=umj->first;
                v.push_back(umj->first);
                //for(auto e:v)   cout<<e<<" ";   cout<<endl;
                if(0<t){
                    umt=umj;
                    if(++umt!=um.end()) dfs( umt, t, v, um, rt);
                }else if(t<0){
                    break;
                }else{//t==0
                    rt.push_back(v);
                    break;
                }
            }
            if(i==umj->second)  i--;
            for( j=-1; j<i; j++){
                t+=umj->first;
                v.pop_back();
            }
        }
        
        return ;
    }
};
