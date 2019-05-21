/*
1047. Remove All Adjacent Duplicates In String

Companies	PayTM
Related Topics	Stack 

Test Cases:
"abbaca"
"aaaaaaaaa"

Runtime: 24 ms
Your runtime beats 70.01 % of cpp submissions.
Memory Usage: 12.5 MB
*/

class Solution {
public:
    string removeDuplicates(string S) {
        // O(n) time&space; remove 2 adjacent; this problem is ambigous
        if(S.size()<1)  return S;
        string rt;
        
        for( int b=0; b<S.size(); b++){
            if(0<rt.size()&&S[b]==rt.back())    rt.pop_back();
            else    rt.push_back(S[b]);
        }
        
        return rt;
    }
};