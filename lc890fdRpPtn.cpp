
/*
Leetcode 890. Find and Replace Pattern

Companies   
Amazon 
Related Topics 
String 

Test Case:
["abc","deq","mee","aqq","dkd","ccc"]
"abb"

Runtime: 4 ms
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
            for( int j=0; j<words[i].size(); j++){// make sure unique mapping in both ways 
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