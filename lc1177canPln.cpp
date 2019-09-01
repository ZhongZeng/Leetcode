/*
1177. Can Make Palindrome from Substring

Companies	Akuna Capital 
Related Topics	Array, String 

Test Case:
"abcda"
[[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]

Runtime: 252 ms	Your runtime beats 66.67 % of cpp submissions.
Memory Usage: 74.9 MB
*/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // O(26*s+26*q) time; O(26*s) space; s contains only lowercase English letters
        vector<bool> rt;
        vector<int> vc(26,0);
        vector<vector<int>> vv={vc};
        for( int i=0; i<s.size(); i++){
            vc[s[i]-'a']+=1;
            vv.push_back(vc);
        }
        
        for( int i=0; i<queries.size(); i++){
            int odd=0;
            for( int j=0; j<26; j++){
                if((vv[queries[i][1]+1][j]-vv[queries[i][0]][j])%2==1)  odd+=1;
            }
            // replace letters w/ their counterparty 
            if((queries[i][1]-queries[i][0]+1)%2==1)    rt.push_back(odd/2<=queries[i][2]?true:false);// allow a single letter in the middle
            else    rt.push_back((odd+1)/2<=queries[i][2]?true:false);
        }
        
        return rt;
    }
};