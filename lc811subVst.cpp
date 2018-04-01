
/*
Leetcode 811. Subdomain Visit Count

Weekly Contest 78  

Test Cases:
["9001 discuss.leetcode.com"]
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]

Runtime: 15 ms

*/


class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        // hash table, string 
        vector<string> rt;
        unordered_map<string, int> um;
        unordered_map<string, int>::iterator umi;
        int i, j , ct;
        string s1, s2, s3;
        
        for( i=0; i<cpdomains.size(); i++){
            for( j=0, ct=0; cpdomains[i][j]!=' '; j++)   ct=ct*10+cpdomains[i][j]-'0';
            
            s1.clear();
            s2.clear();
            s3.clear();
            while( ++j<cpdomains[i].size()&&cpdomains[i][j]!='.' )  s1.push_back(cpdomains[i][j]);
            
            if(j+1<cpdomains[i].size()) s1.push_back('.');
            while( ++j<cpdomains[i].size()&&cpdomains[i][j]!='.' ){
                s1.push_back(cpdomains[i][j]);
                s2.push_back(cpdomains[i][j]);
            }
            
            if(j+1<cpdomains[i].size()){
                s1.push_back('.');
                s2.push_back('.');
            }
            while( ++j<cpdomains[i].size()&&cpdomains[i][j]!='.' ){
                s1.push_back(cpdomains[i][j]);
                s2.push_back(cpdomains[i][j]);
                s3.push_back(cpdomains[i][j]);
            }
            
            //cout<<ct<<": "<<s1<<", "<<s2<<", "<<s3<<endl;
            
            umAdd(s1, um, ct);
            umAdd(s2, um, ct);
            umAdd(s3, um, ct);
        }
        
        for(umi=um.begin(); umi!=um.end(); umi++){
            s1.clear();
            s1.append(to_string(umi->second));
            s1.push_back(' ');
            s1.append(umi->first);
            rt.push_back(s1);
        }
        
        return rt;
    }
    
    void umAdd(string& s, unordered_map<string, int>& um, int& ct){
        if(!s.empty()){
            unordered_map<string, int>::iterator umi=um.find(s);
            if(umi!=um.end())   umi->second+=ct;
            else    um.emplace(s, ct);
        }
        return ;
    }
    
};
