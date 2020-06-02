/*
1234. Replace the Substring for Balanced String

Medium
Companies	Accolite
Related Topcis	Two Pointers, String 

Test Cases:
"WQWRQQQW"
"QWER"
"QQWE"
"QQQW"
"QQQQ"

Runtime: 64 ms, faster than 76.91% of C++ online submissions for Replace the Substring for Balanced String.
Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Replace the Substring for Balanced String.
Next challenges: Text Justification, Parse Lisp Expression, Longest Happy Prefix
*/

class Solution {
public:
    int balancedString(string s) {
        // 2-pointer; s.size()%4==0; QWER
        int b, e, len=s.size();// ch: total # to remove
        unordered_map<char,int> po={{'Q',0},{'W',1},{'E',2},{'R',3}};
        vector<int> rp(4, -s.size()/4), cr(4, 0);// rp: >0: to remove; <0: to add
        
        for( int i=0; i<s.size(); i++)  rp[po[s[i]]]+=1;
        
        if(canBalance( rp, cr)) return 0;
        for( b=0, e=0; e<s.size()+1; ){// [b,e); if [b1,e1) is shortest substr, it must be visited
            if(canBalance( rp, cr)){// 0<e-b guranteed
                len=len<e-b?len:e-b;
                cr[po[s[b++]]]-=1;
            }else{
                cr[po[s[e++]]]+=1;
            }
        }
        
        return len;
    }
    
protected:
    bool canBalance( vector<int> & rp, vector<int> & cr){
        // need to remove at least max(rp[i],0) 
        for( int i=0; i<rp.size(); i++)
            if(0<rp[i]&&cr[i]<rp[i])    return false;
        return true;
    }
};