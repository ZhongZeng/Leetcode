
/*
Leetcode 438. Find All Anagrams in a String

Related Topics 
Hash Table 
Similar Questions 
Valid Anagram Permutation in String 

Next challenges: Permutation in String

Test Cases:
"cbaebabacd"
"abc"
"ababa"
"ab"
"cababa"
"ab"

Runtime: 36 ms
Your runtime beats 56.37 % of cpp submissions.
This solution is faster, bz it eliminates many emplace&erase.

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vc={};
        if( s.size()<p.size() ) return vc; 
        unordered_map<char,int> um;
        unordered_map<char,int>::iterator umi;
        int dif=p.size();
        // -:short of; +:extra
        // travese p
        for(string::iterator si=p.begin(); si!=p.end(); si++){
            umi=um.find(*si);
            if(umi!=um.end())   umi->second--;
            else    um.emplace( *si, -1);
        }
        
        // travese s[0,p.size())
        for(int i=0; i<p.size(); i++){
            umi=um.find(s[i]);
            if( umi!=um.end() ){                
                if(umi->second<0)   dif--;
                else    dif++;
                umi->second++;
            }else{
                um.emplace(s[i], 1);
                dif++;
            }            
        }
        if(dif==0)  vc.push_back(0);
        
        // travese s
        for(int i=0; i<s.size()-p.size() ; i++){
            umi=um.find(s[i]);
            if( umi!=um.end() ){                
                if(0<umi->second)   dif--;
                else    dif++;
                umi->second--;
            }else{
                um.emplace(s[i], -1);
                dif++;
            }
            
            umi=um.find(s[i+p.size()]);
            if( umi!=um.end() ){                
                if(umi->second<0)   dif--;                    
                else    dif++;  
                umi->second++;
            }else{
                um.emplace(s[i+p.size()], 1);
                dif++;
            }
            
            if(dif==0)  vc.push_back(i+1);
        }
        
        return vc;
    }
};

/*
// Runtime: 49 ms
// Your runtime beats 30.41 % of cpp submissions.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vc={};
        if( s.size()<p.size() ) return vc; 
        unordered_map<char, int> um;
        unordered_map<char, int>::iterator umi;
        // -:short of; +:extra
        // travese p
        for(string::iterator si=p.begin(); si!=p.end(); si++){
            umi=um.find(*si);
            if(umi!=um.end())   umi->second--;
            else    um.emplace( *si, -1);
        }
        
        // travese s[0,p.size())
        for(int i=0; i<p.size(); i++){
            umi=um.find(s[i]);
            if( umi!=um.end() ){
                if(umi->second!=-1)  umi->second++;
                else    um.erase(umi);
            }else{
                um.emplace(s[i], 1);
            }            
        }
        if(um.empty()) vc.push_back(0);
        
        // travese s
        for(int i=0; i<s.size()-p.size() ; i++){
            umi=um.find(s[i]);
            if( umi!=um.end() ){
                if( umi->second!=1 ){
                    umi->second--;
                }else{
                    um.erase(umi);
                }                
            }else{
                um.emplace(s[i], -1);
            }
            
            umi=um.find(s[i+p.size()]);
            if( umi!=um.end() ){
                if( umi->second!=-1 ){
                    umi->second++;
                }else{
                    um.erase(umi);
                }                
            }else{
                um.emplace(s[i+p.size()], 1);
            }
            
            if(um.empty()) vc.push_back(i+1);
        }
        
        return vc;
    }
};
*/