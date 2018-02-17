/*

Leetcode 161. One Edit Distance

Companies 
Facebook, Uber, Twitter, Snapchat 
Related Topics 
String 
Similar Questions 
Edit Distance

Next challenges: Edit Distance

Test Cases:
""
""
"abc"
"bc"
"abc"
"abc"
"abc"
"a"
""
"a"
"a"
"ac"

Runtime: 4 ms
Your runtime beats 18.14 % of cpp submissions.

*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        //Edit Distance: a) Insert a character; b) Delete a character; c) Replace a character
        bool f=true;
        int i;
        if(t.size()<s.size()){
            return isOneEditDistance(t, s);
        }else if(1<t.size()-s.size()){
            return false;
        }else if(t.size()-s.size()==1){
            for( i=0; i<s.size(); i++){
                if(s[i]!=t[i]){
                    f=false;
                    break;
                }
            }
            if(i==s.size()) return true;
            for( ; i<s.size(); i++) if(s[i]!=t[i+1])  return false;
        }else{
            for( i=0; i<s.size(); i++){
                if(s[i]!=t[i]){
                    if(f)   f=false;
                    else    return false;
                }
            }
        }
        
        return !f;
    }
};
