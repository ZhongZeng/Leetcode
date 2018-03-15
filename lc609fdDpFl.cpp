

/*

Leetcode 609. Find Duplicate File in System

Companies 
Dropbox
Related Topics 
Hash Table, String 

Next challenges: Multiply Strings, 
Palindromic Substrings, Count Different Palindromic Subsequences

Test Cases:
["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]

Runtime: 104 ms
Your runtime beats 35.36 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<string> vs;
        vector<vector<string>> rt;
        unordered_map<string, unordered_set<string>> um;
        unordered_map<string, unordered_set<string>>::iterator umi;
        unordered_set<string>::iterator usi;
        
        for(int i=0; i!=paths.size(); i++)  contnt( paths[i], um);
        
        for( umi=um.begin(); umi!=um.end(); umi++){
            if(1<umi->second.size()){
                vs.clear();
                for( usi=umi->second.begin(); usi!=umi->second.end(); usi++)    vs.push_back(*usi);
                rt.push_back(vs);
            }
        }
        
        return rt;
    }
    
    void contnt(string& s, unordered_map<string, unordered_set<string>>& um){
        int j;
        string path, f, c, fp;
        vector<string> fl;// file
        vector<string> ct;// content
        unordered_set<string> us;
        unordered_map<string, unordered_set<string>>::iterator umi;
        
        for( j=0; j<s.size(); j++){
            if(s[j]!=' ')   path.push_back(s[j]);
            else    break;
        }

        while( ++j<s.size()){
            for( f.clear(); j<s.size(); j++){
                if(s[j]!='(')   f.push_back(s[j]);
                else    break;
            }
            fl.push_back(f);
            
            for( c.clear(); j<s.size(); j++){
                if(s[j]!=')')   c.push_back(s[j]);
                else    break;
            }
            ct.push_back(c);
            j++;
        }
        
        for( j=0; j<fl.size(); j++){
            umi=um.find(ct[j]);
            fp=path;
            fp.push_back('/');
            fp.append(fl[j]);
            if(umi!=um.end()){
                umi->second.emplace(fp);
            }else{
                us.clear();
                us.emplace(fp);
                um.emplace(ct[j], us);
            }
        }

        return ;
    }
};
