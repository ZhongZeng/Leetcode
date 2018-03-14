
/*
Leetcode 249. Group Shifted Strings

Companies 
Google, Uber
Related Topics 
Hash Table, String 
Similar Questions 
Group Anagrams

Test Cases:
["abc","bcd","acef","xyz","az","ba","a","z","abc"]

Next challenges: Validate IP Address, Implement Magic Dictionary, Basic Calculator IV

Runtime: 6 ms
Your runtime beats 45.96 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // reduce string to a started, instead of using vector<int>
        // assuming no duplicate in strings, by testing ["abc","abc"]
        string rs;
        vector<string> vs;
        vector<vector<string>> rt;
        unordered_map<string,vector<string>> um;
        unordered_map<string,vector<string>>::iterator umi;
        
        for(int i=0; i<strings.size(); i++){
            rs=reduc(strings[i]); 
            //cout<<strings[i]<<" "<<rs<<endl;
            umi=um.find(rs);
            if(umi!=um.end()){
                umi->second.push_back(strings[i]);
            }else{
                vs.clear();
                vs.push_back(strings[i]);
                um.emplace(rs,vs);
            }
        }
        
        for( umi=um.begin(); umi!=um.end(); umi++)  rt.push_back(umi->second);
        
        return rt;
    }
    
protected:    
    string reduc(string& s){
        string rs;
        int sh=s[0]-'a';
        for(int i=0, t; i<s.size(); i++){
            t=s[i]-sh;
            if(t<97)    rs.push_back((char)(t+26));
            else if(122<t)  rs.push_back((char)(t-26));
            else    rs.push_back((char)(t));
        }
        return rs;
    }
};
