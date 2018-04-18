
/*
Leetcode 10. Regular Expression Matching

Companies 
Google, Facebook, Uber, Twitter, Airbnb 
Related Topics 
String, Dynamic Programming, Backtracking 
Similar Questions 
Wildcard Matching

Next challenges: Word Ladder II, 
Guess Number Higher or Lower II, Longest Uncommon Subsequence II

Test Cases:
"aab"
"c*a*b"
"aa"
"c*a*"
"aab"
"c*a*b"
"ab"
".*"
"aa"
"a"
"aa"
"a*"
"cb"
".a"
"adceb"
"a*b*"
"acdcb"
"a*c.b"

Runtime: 14 ms
Your runtime beats 76.00 % of cpp submissions.

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        // O(m*n) time 
        // '.' Matches any single character.
        // '*' Matches zero or more of the preceding element.
        // s could be empty and contains only lowercase letters a-z.
        // p could be empty and contains only lowercase letters a-z, and characters like . or *.
        
        vector<int> vc(1, 1), vd;
        // isMatch( "", p[:j])
        for(int j=0; j<p.size(); j++){
            if(j<p.size()-1&&p[j+1]=='*'){
                if(vc.back()==1)    vc.push_back(1);
                else    vc.push_back(0);
                j++;
            }else{
                vc.push_back(0);
            }
        }
        
        // isMatch( s[:i], p[:j] )
        for(int i=0; i<s.size(); i++){
            vd={false};
            for(int j=0, k=0; j<p.size(); j++, k++){// j in p; k in vc
                if(j+1<p.size()&&p[j+1]=='*'){
                    if(vd.back()==1){// DP from isMatch( s[:i], p[:j-1] )
                        vd.push_back(1);
                    }else if(vc[k+1]==1&&(p[j]==s[i]||p[j]=='.')){// DP from isMatch( s[:i-1], p[:j] )
                        vd.push_back(1);
                    }else if(vc[k]==1&&(p[j]==s[i]||p[j]=='.')){// DP from isMatch( s[:i-1], p[:j-1] )
                        vd.push_back(1);
                    }else{
                        vd.push_back(0);
                    }
                    j++;
                }else{
                    if(vc[k]==1&&(p[j]==s[i]||p[j]=='.')){// DP from isMatch( s[:i-1], p[:j-1] ) 
                        vd.push_back(1);
                    }else{
                        vd.push_back(0);
                    }
                }
            }
            //for(auto e:vd)  cout<<e<<" ";   cout<<endl;
            vc=vd;
        }
        
        return vc.back();
    }
};
