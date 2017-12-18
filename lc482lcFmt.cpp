

/*
Leetcode 482. License Key Formatting

Next challenges: Count Univalue Subtrees, 
Concatenated Words, Split Array into Consecutive Subsequences

Test Cases:
"2-5g-3-J"
2
"5F3Z-2e-9-w"
3
"5F3Z-2e-9-w"
4

Runtime: 13 ms
Your runtime beats 28.77 % of cpp submissions.

*/


class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int ct=0;
        char t;
        string rs;
        for(int i=S.size()-1; i!=-1; i--){
            if(S[i]!='-'){
                if(-1<S[i]-'a'&&-1<'z'-S[i])    rs.push_back(S[i]-'z'+'Z');
                else    rs.push_back(S[i]);
                ct++;
                if(ct==K){
                    rs.push_back('-');
                    ct=0;
                }
            }
        }
        
        if(rs.back()=='-')  rs.pop_back();
        
        for(int i=0, j=rs.size()-1; i<j; i++, j--){
            t=rs[i];
            rs[i]=rs[j];
            rs[j]=t;
        }
        
        return rs;
    }
    
};