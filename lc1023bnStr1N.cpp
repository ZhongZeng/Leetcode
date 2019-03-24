/*
1023. Binary String With Substrings Representing 1 To N

Next challenges: Text Justification, Mini Parser, Basic Calculator IV

Test Cases:
"0110"
3
"0110"
4

Runtime: 4 ms
Memory Usage: 8.5 MB

https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/discuss/261229/
*/

class Solution {
public:
    bool queryString(string S, int N) {
        // math +backtrack +bit; O(M*20+N) time; S.size() in [1,10^3]; N in [1,10^9]
        vector<int> vc(N+1,0);// [1,N] ignoring 0 
        int i, j, t, d;
        
        for( i=S.size()-1; -1<i; i--){
            for( t=0, d=1, j=i; -1<j&&i-20<j; j--, d=d<<1){
                if(S[j]=='1') t+=d;
                if(t<=N)    vc[t]=1;
                else    break;
            }
        }
        
        for( i=1; i<vc.size(); i++){
            if(vc[i]==0)    return false;
        }
        
        return true;
    }
};