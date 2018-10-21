

/*
Leetcode 926. Flip String to Monotone Increasing

Runtime: 4 ms

*/

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        // O(n) time; some '0's(possibly 0)
        int o=0, z=0, rt=S.size();// previous one, trailing zero(inclusive)
        
        for( int i=0; i<S.size(); i++){
            if(S[i]=='0')   z++;
        }
        
        for( int i=0; i<S.size(); i++){
            rt=z+o<rt?z+o:rt;
            if(S[i]=='0')   o--;
            else    z++;
        }
        rt=z+o<rt?z+o:rt;
        
        return rt;
    }
};