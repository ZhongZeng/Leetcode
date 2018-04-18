
/*
Leetcode 44. Wildcard Matching

Companies 
Google, Facebook, Twitter, Snapchat, Two Sigma 
Related Topics 
String, Dynamic Programming, Backtracking, Greedy 
Similar Questions 
Regular Expression Matching

Next challenges: Regular Expression Matching

Test Cases:
"aa"
"a"
"aa"
"*"
"cb"
"?a"
"adceb"
"*a*b"
"acdcb"
"a*c?b"

Runtime: 113 ms
Your runtime beats 12.32 % of cpp submissions.
Runtime: 114 ms
Your runtime beats 12.16 % of cpp submissions.

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        // DP, O(m*n) time; MITOCW 6.006 Intro2Algo 21.DPIII blowed my mind!!, which is a more generalized case. 
        // '?' Matches any single character.
        // '*' Matches any sequence of characters (including the empty sequence).
		// I should apply backtrack here as well. 
        
        vector<bool> vc(1, true), vd;
        // empty string w/ p[:j] 
        for(int j=0; j<p.size(); j++){
            if(p[j]!='*'||vc.back()!=true)  vc.push_back(false);
            else    vc.push_back(true);
        }
        
        // s[:i] w/ p[:j] 
        for(int i=0; i<s.size(); i++){
            vd={false};
            for(int j=0; j<p.size(); j++){ 
                if(vd.back()==true&&p[j]=='*'){// DP from s[:i] w/ p[:j-1] 
                    vd.push_back(true);
                }else if(vc[j+1]==true&&p[j]=='*'){// DP from s[:i-1] w/ p[:j] 
                    vd.push_back(true);
                }else if(vc[j]==true&&(p[j]==s[i]||p[j]=='?'||p[j]=='*')){// s[:i-1] w/ p[:j-1] 
                    vd.push_back(true);
                }else{
                    vd.push_back(false);
                }
            }
            vc=vd;
            //for(auto e:vc)  cout<<e<<" ";   cout<<endl;
        }
        
        return vc.back();
    }
};
