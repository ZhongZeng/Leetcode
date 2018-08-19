
/*
Leetcode 888. Fair Candy Swap

Companies   
Fidessa
Related Topics 
Array 

Test Cases: 
[1,1]
[2,2]
[1,2]
[2,3]
[2]
[1,3]
[1,2,5]
[2,4]

Runtime: 92 ms
*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // string, hash table, backtrack 
        vector<string> rt;
        
        for( int i=0; i<words.size(); i++){
            if(words[i].size()!=pattern.size()) continue;
            bool t=true;
            unordered_map<char,char> uw, up;
            unordered_map<char,char>::iterator umi;
            for( int j=0; j<words[i].size(); j++){
                umi=uw.find(words[i][j]);
                if(umi!=uw.end()){
                    if(umi->second!=pattern[j]){
                        t=false;
                        break;
                    }
                }else{
                    uw.emplace(words[i][j],pattern[j]);
                }
                
                umi=up.find(pattern[j]);
                if(umi!=up.end()){
                    if(umi->second!=words[i][j]){
                        t=false;
                        break;
                    }
                }else{
                    up.emplace(pattern[j],words[i][j]);
                }
            }
            if(t)   rt.push_back(words[i]);
        }
        
        return rt;
    }
};
