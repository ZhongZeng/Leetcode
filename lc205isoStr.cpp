
/*
Leetcode 205. Isomorphic Strings

Related Topics 
Hash Table 
Similar Questions 
Word Pattern 

Next challenges: Word Pattern

Test Cases:
"egge"
"addd"
"egg"
"add"

Runtime: 9 ms
You are here! 
Your runtime beats 41.06 % of cpp submissions.


*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())  return false;
        unordered_map<char, char> um, un;
        unordered_map<char, char>::iterator umi;
        for(int i=0; i!=s.size(); i++){
            umi=um.find(s[i]);
            if( umi!=um.end() ){
                if( umi->second!=t[i] ){
                    return false;
                }
            }else{
                um.emplace(s[i],t[i]);
            }            
        }
        
        for(int i=0; i!=s.size(); i++){
            umi=un.find(t[i]);
            if( umi!=un.end() ){
                if( umi->second!=s[i] ){
                    return false;
                }
            }else{
                un.emplace(t[i],s[i]);
            }            
        }
        
        return true;
    }
};
