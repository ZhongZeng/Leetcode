
/*
Leetcode 929. Unique Email Addresses

Runtime: 24 ms

*/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> us;
        unordered_set<string>::iterator usi;
        string s;
        int i, j;
        
        for( i=0; i<emails.size(); i++){
            s.clear();
            for( j=0; j<emails[i].size(); j++){
                if(emails[i][j]=='.'){
                    
                }else if(emails[i][j]=='+'){
                    for( ; j<emails[i].size()&&emails[i][j]!='@'; j++){}
                    break;
                }else if(emails[i][j]=='@'){
                    break;
                }else{
                    s.push_back(emails[i][j]);
                }
            }
            
            for( ; j<emails[i].size(); j++){
                s.push_back(emails[i][j]);
            }
            
            usi=us.find(s);
            if(usi==us.end())   us.emplace(s);
        }
        
        return us.size();
    }
};
