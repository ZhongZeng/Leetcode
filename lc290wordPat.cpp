

/*
Leetcode 290. Word Pattern

Related Topics 
Hash Table 
Similar Questions 
Isomorphic Strings, Word Pattern II 

Next challenges: Word Pattern II

Runtime: 3 ms
You are here! 
Your runtime beats 1.04 % of cpp submissions.

Runtime: 0 ms
You are here! 
Your runtime beats 42.66 % of cpp submissions.

*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // the instrcution is vague
        // instruction: "ecce" "dog cat cat dog" should also be true
        // the length of elements in pattern and str may not match
        unordered_set<char> us;
        unordered_map<string, char> um;
        unordered_map<string, char>::iterator umi;
        int i=0, j=0, p=0;// i,j:start and end position in str; p:position in pattern; c:unique substring
        for( ; i!=str.size(); i++){
            if( str[i]==' ' ){
                umi = um.find( str.substr(j, i-j) );
                if( umi!=um.end() ){                 
                    if( pattern[p] != umi->second ){
                        return false;
                    }        
                }else{
                    if( us.find( pattern[p] )!=us.end() ){
                        return false;
                    }else{
                        um.emplace( str.substr(j, i-j), pattern[p] );
                        us.emplace( pattern[p] );
                    }                    
                }                    
                j=i+1;
                ++p;
            }
        }
        
        umi = um.find( str.substr(j, i-j) );
        if( umi!=um.end() ){                 
            if( pattern[p] != umi->second ){
                return false;
            }        
        }else{
            if( us.find( pattern[p] )!=us.end() ){
                return false;
            }                 
        }
        
        return p!=pattern.size()-1 ? false : true; // because no ++p; for the last one
    }
};
