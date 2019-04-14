/*
1023. Camelcase Matching

Companies	Google
Related Topics	String, Trie (trie not needed; greedy suggested)

Test Cases:
["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
"FB"
["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
"FoBa"
["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]
"FoBaT"

Runtime: 4 ms
Memory Usage: 8.5 MB
Your runtime beats 100.00 % of cpp submissions.

Next challenges: Palindrome Pairs, Mini Parser, Bold Words in String

*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        // 2-pointer, greedy 
        vector<bool> rt;
        for( int i=0; i<queries.size(); i++)    rt.push_back( matchPt(queries[i],pattern)?true:false );
        return rt;
    }
    
protected:
    bool isLower(char c){
        return (c-'a'<27)&&(-1<c-'a');
    }
    
    bool matchPt( string& s, string& p){
        int i=0, j=0;
        for( ; i<s.size()&&j<p.size(); i++){
            if(!isLower(s[i])){// upper case must match 
                if(s[i]!=p[j])  return false;
                else    j++;
            }else{// match as manny lower case as possible 
                if(s[i]==p[j])  j++;
            }
        }
        for( ; i<s.size(); i++) if(!isLower(s[i]))   return false;
        return j==p.size();
    }
};