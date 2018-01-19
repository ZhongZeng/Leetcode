

/*
Leetcode 49. Group Anagrams

Related Topics 
Hash TableString
Similar Questions 
Valid Anagram, Group Shifted Strings

Next challenges: Group Shifted Strings

Test Case:
["eat","tea","tan","ate","nat","bat"]

Runtime: 31 ms
Your runtime beats 66.76 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string s;
        unordered_map<string, vector<string>> um;
        unordered_map<string, vector<string>>::iterator umi;
        vector<string> vc;
        vector<vector<string>> vs;
        
        for(int i=0; i<strs.size(); i++){
            s=strs[i];
            sort(s.begin(), s.end());
            umi=um.find(s);
            if(umi!=um.end()){
                umi->second.push_back(strs[i]);
            }else{
                vc={strs[i]};
                um.emplace(s,vc);
            }
        }
        
        for(umi=um.begin(); umi!=um.end(); umi++){
            vs.push_back(umi->second);
        }
        
        return vs;
    }
};