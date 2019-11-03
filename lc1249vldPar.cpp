/*
1249. Minimum Remove to Make Valid Parentheses

Company	Facebook
Related Topic	String, Stack

Test Cases:
"lee(t(c)o)de)"
"a)b(c)d"
"))(("
"(a(b(c)d)"

Runtime: 36 ms	Your runtime beats 25.00 % of cpp submissions.
Memory Usage: 13.2 MB
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // O(n) time&space
        string rt;
        for( int i=0, p=0; i<s.size(); i++){
            if(s[i]=='(')   p++;
            else if(s[i]==')')  p--;
            if(p<0) p=0;
            else    rt.push_back(s[i]);
        }
        s=rt;
        rt.clear();
        for( int i=s.size()-1, p=0; -1<i; i--){
            if(s[i]=='(')   p++;
            else if(s[i]==')')  p--;
            if(0<p) p=0;
            else    rt.push_back(s[i]);
        }
        for( int i=0, j=rt.size()-1; i<j; i++, j--){
            char c=rt[i];
            rt[i]=rt[j];
            rt[j]=c;
        }
        return rt;
    }
};