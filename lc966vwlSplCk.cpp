/*
966. Vowel Spellchecker

Related Topics: Hash Table, String 

Test Cases:
["KiTe","kite","hare","Hare"]
["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]

Runtime: 100 ms, faster than 100.00% of C++ online submissions for Vowel Spellchecker.
*/

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // hash table better than tire here; string on consist of english letter
        vector<string> vs;
        unordered_map<string,string> um;
        unordered_map<string,string>::iterator umi;
        
        for( int i=0; i<wordlist.size(); i++){
            umi=um.find(wordlist[i]);
            if(umi!=um.end())   umi->second=wordlist[i];// b/c same word or caplization 
            else    um.emplace(wordlist[i],wordlist[i]);
            
            um.emplace(caplization(wordlist[i]),wordlist[i]);// if exist, emplace won't take place; first occurence guranteed 

            um.emplace(vowel(wordlist[i]),wordlist[i]);// could have multiple match b/c caplization 
        }
        
        for( int i=0; i<queries.size(); i++){
            umi=um.find(queries[i]);
            if(umi!=um.end()){
                vs.push_back(umi->second);
            }else{
                umi=um.find(caplization(queries[i]));
                if(umi!=um.end()){
                    vs.push_back(umi->second);
                }else{
                    umi=um.find(vowel(queries[i]));
                    vs.push_back(umi!=um.end()?umi->second:"");
                }
            }
        }
        
        return vs;
    }
    
protected:
    string caplization(string & t){
        string s;
        for( int j=0; j<t.size(); j++){
            if(t[j]-'a'<27&&-1<t[j]-'a')    s.push_back((char)(t[j]-32));
            else    s.push_back(t[j]);
        }
        return s;
    }
    
    string vowel(string & t){// caplization&&vowel 
        string s=caplization(t), u;
        for( int j=0; j<s.size(); j++){
            if(s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U')   u.push_back('0');
            else    u.push_back(s[j]);
        }
        return u;
    }
};