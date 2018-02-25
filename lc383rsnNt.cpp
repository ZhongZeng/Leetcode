
/*
Leetcode 383. Ransom Note

Companies 
Apple
Related Topics 
String
Similar Questions 
Stickers to Spell Word

Next challenges: Stickers to Spell Word

Test Cases:
"a"
"b"
"aa"
"aba"

Runtime: 35 ms
Your runtime beats 37.79 % of cpp submissions.

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // hash table, O(m+n)
        if(ransomNote.size()<1) return true;
        unordered_map<char,int> um;
        unordered_map<char,int>::iterator umi;
        for(int i=0; i<ransomNote.size(); i++){
            umi=um.find(ransomNote[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(ransomNote[i],1);
        }
        
        for(int i=0; i<magazine.size(); i++){
            umi=um.find(magazine[i]);
            if(umi!=um.end())   umi->second-=1;
        }
        
        for(umi=um.begin(); umi!=um.end(); umi++){
            if(0<umi->second)   return false;
        }
        
        return true;
    }
};
