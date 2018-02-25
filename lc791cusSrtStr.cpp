
/*
Leetcode 791. Custom Sort String

Weekly Contest 73  

Test Cases: 
"cba"
"abcd"
"cba"
"acbabefcd"
""
"acbabefcd"
"ab"
""
""
""

Runtime: 3 ms

*/

class Solution {
public:
    string customSortString(string S, string T) {
        // hash table, O(n) time
        if(T.size()<1)  return T;
        string rt;
        unordered_map<char,int> um;
        unordered_map<char,int>::iterator umi;
        for(int i=0; i<T.size(); i++){
            umi=um.find(T[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(T[i],1);
        }
        
        for(int i=0; i<S.size(); i++){
            umi=um.find(S[i]);
            for(int j=0; j<umi->second; j++)    rt.push_back(umi->first);
            umi->second=0;
        }
        
        for(umi=um.begin(); umi!=um.end(); umi++){
            for(int j=0; j<umi->second; j++)    rt.push_back(umi->first);
            umi->second=0;
        }
        
        return rt;
    }
};
