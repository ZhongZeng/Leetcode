
/*
Leetcode 567. Permutation in String

Related Topics 
Two Pointers 
Similar Questions 
Minimum Window Substring, Find All Anagrams in a String 

Test Cases:
"ab"
"eidbaooo"

Runtime: 13 ms
Your runtime beats 42.57 % of cpp submissions.

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Is this any diff from 438. Find All Anagrams in a String?
        // I use code from lc438.
        // Tag:2-pointer; hash_table
        if(s2.size()<s1.size()) return false;
        unordered_map<char,int> um;
        unordered_map<char,int>::iterator umi;
        int dif=s1.size();
        // -:short of; +:extra
        // travese s1
        for(string::iterator si=s1.begin(); si!=s1.end(); si++){
            umi=um.find(*si);
            if(umi!=um.end())   umi->second--;
            else    um.emplace( *si, -1);
        }
        
        // travese s2[0,s1.size())
        for(int i=0; i<s1.size(); i++){
            umi=um.find(s2[i]);
            if( umi!=um.end() ){                
                if(umi->second<0)   dif--;
                else    dif++;
                umi->second++;
            }else{
                um.emplace(s2[i], 1);
                dif++;
            }            
        }
        if(dif==0)  return true;
        
        // travese s2
        for(int i=0; i<s2.size()-s1.size() ; i++){
            umi=um.find(s2[i]);
            if( umi!=um.end() ){                
                if(0<umi->second)   dif--;
                else    dif++;
                umi->second--;
            }else{
                um.emplace(s2[i], -1);
                dif++;
            }
            
            umi=um.find(s2[i+s1.size()]);
            if( umi!=um.end() ){                
                if(umi->second<0)   dif--;                    
                else    dif++;  
                umi->second++;
            }else{
                um.emplace(s2[i+s1.size()], 1);
                dif++;
            }
            
            if(dif==0)  return true;
        }        
        
        return false;
    }
};