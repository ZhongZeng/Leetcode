/*
1282. Group the People Given the Group Size They Belong To

Companies	Roblox
Related Topics	Greedy

Test Cases:
[3,3,3,3,3,1,3]
[2,1,3,3,3,2]

Runtime: 24 ms	Your runtime beats 80.00 % of cpp submissions.
Memory Usage: 11.6 MB
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // greedy, O(n) time&space; groupSizes[i] in [1,n] 
        vector<vector<int>> rt;
        unordered_map<int,vector<int>> um;
        unordered_map<int,vector<int>>::iterator umi;
        
        for( int i=0; i<groupSizes.size(); i++){
            umi=um.find(groupSizes[i]);
            if(umi!=um.end()){
                umi->second.push_back(i);
            }else{
                vector<int> vc={i};
                um.emplace(groupSizes[i], vc);
            }
        }
        
        for( umi=um.begin(); umi!=um.end(); umi++){
            vector<int> vc;
            for( int i=0, c=0; i<umi->second.size(); i++){
                vc.push_back(umi->second[i]);
                if(++c==umi->first){
                    c=0;
                    rt.push_back(vc);
                    vc.clear();
                }
            }
        }
        
        return rt;
    }
};