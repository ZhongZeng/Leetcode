/*
1614. Maximum Nesting Depth of the Parentheses

Companies:	Bloomberg, Facebook 
Related Topics:	String 
Similar Questions:	Maximum Nesting Depth of Two Valid Parentheses Strings

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 6.2 MB	Your memory usage beats 15.19 % of cpp submissions.
*/

class Solution {
public:
    int maxDepth(string s) {
        int max=0, depth=0;
        for( int i=0; i<s.size(); i++){
            if(s[i]=='('){
                depth++;
                max=max<depth?depth:max;
            }else if(s[i]==')'){
                depth--;
            }
        }
        return max;
    }
};