
/*
Leetcode 940. Distinct Subsequences II

Test Cases:
"zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn"
"abc"
"aaa"
"aba"
"abb"

Runtime: 4 ms

*/

class Solution {
public:
    int distinctSubseqII(string S) {
        // DP; S contains only lowercase letters.
        if(S.size()<1)  return 0;
        int rt=2, t;// 1st char+empty string
        vector<int> vc(26,0);// distinctSubseqII( last occurance ending previous to (char)('a'+i)] ) 
        vc[S[0]-'a']=1;
        
        for( int i=1; i<S.size(); i++){
            t=rt;
            rt=(rt<<1)-vc[S[i]-'a'];//((rt<<1)%1000000007+1000000007-vc[S[i]-'a'])%1000000007
            if(rt<0)    rt+=1000000007;
            else if(1000000007<rt)  rt-=1000000007;
            vc[S[i]-'a']=t;
            //cout<<vc[S[i]-'a']<<","<<rt<<"; ";
        }
        
        return (rt-1)%1000000007;// remove empty string 
    }
};

