
/*
Leetcode 721. Accounts Merge

Related Topics 
Depth-first Search, Union Find
Similar Questions 
Redundant Connection, Sentence Similarity, Sentence Similarity II

Next challenges: Sentence Similarity II

Test Case:
[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

Runtime: 128 ms
Your runtime beats 62.14 % of cpp submissions.
Runtime: 142 ms
Your runtime beats 54.73 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        string sd;
        vector<string> vc;
        unordered_map<string,vector<string>> um;// email, name, email ID, #
        unordered_map<string,vector<string>>::iterator umi, umj;
        unordered_map<string,vector<string>> uv;
        unordered_map<string,vector<string>>::iterator uvi;
        vector<vector<string>> rt;
        
        // quick union, no weighted quick union/path compression
        for(int i=0; i<accounts.size(); i++){
            vc={accounts[i][0],accounts[i][1]};// name, email ID
            for(int j=1; j<accounts[i].size(); j++){
                umi=um.find(accounts[i][j]);
                if(umi!=um.end()){
                    for( ; umi->first!=umi->second[1]; umi=um.find(umi->second[1])){}
                    for( umj=um.find(vc[1]); umj->first!=umj->second[1]; umj=um.find(umj->second[1])){}
                    umj->second[1]=umi->second[1];
                    vc[1]=umi->second[1];
                }else{
                    um.emplace(accounts[i][j], vc);
                }
            }
        }
        //for(auto ele:um)    cout<<ele.first<<" "<<ele.second[0]<<" "<<ele.second[1]<<endl;
        
        // quick find
        for(umi=um.begin(); umi!=um.end(); umi++){
            for(umj=umi; umj->first!=umj->second[1]; umj=um.find(umj->second[1])){}
            uvi=uv.find(umj->second[1]);
            if(uvi!=uv.end()){
                uvi->second.push_back(umi->first);
            }else{
                vc={umj->second[0], umi->first};
                uv.emplace(umj->first, vc);
            }
        }
        
        // return vector 
        for(uvi=uv.begin(); uvi!=uv.end(); uvi++){
            sort(uvi->second.begin()+1, uvi->second.end());
            rt.push_back(uvi->second);
        }
        
        return rt;
    }
};
