
/*
Leetcode 844. Backspace String Compare

Weekly Contest 87  
652 / 3026

Test Cases:
"ab#c"
"ad#c"
"ab##"
"c#d#"
"a##c"
"#a#c"
"a#c"
"b"

Runtime: 5 ms

*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // O(m) time&space
        int i, j;
        string s1, s2;
        for( i=0; i<S.size(); i++){
            if(S[i]!='#'){
                s1.push_back(S[i]);
            }else{
                if(!s1.empty()) s1.pop_back();
            }
        }

        for( i=0; i<T.size(); i++){
            if(T[i]!='#'){
                s2.push_back(T[i]);
            }else{
                if(!s2.empty()) s2.pop_back();
            }
        }
        
        if(s1.size()!=s2.size())    return false;
        for( i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i])    return false;
        }
        
        return true;
    }
};