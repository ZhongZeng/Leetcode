
/*
Leetcode 387. First Unique Character in a String

Related Topics 
Hash Table, String 
Similar Questions 
Sort Characters By Frequency 

Next challenges: Sort Characters By Frequency

Test Cases:
"leetcode"
""
"loveleetcode"

Runtime: 62 ms
Your runtime beats 54.99 % of cpp submissions.

*/



class Solution {
public:
    int firstUniqChar(string s) {
        // O(n) time
        if(s.size()<1)  return -1;
        unordered_map<char,pair<int,int>> um; // number, location, # appears
        unordered_map<char,pair<int,int>>::iterator umi;
        int mn=s.size();
        for(int i=0; i!=s.size(); i++){
            umi=um.find(s[i]);
            if(umi!=um.end())   umi->second.second+=1;
            else um.emplace(s[i],make_pair(i,1));
        }
        
        for(umi=um.begin(); umi!=um.end(); umi++){
            if(umi->second.second==1&&umi->second.first<mn)
                mn=umi->second.first;
        }

        return mn!=s.size()?mn:-1;
    }
};
