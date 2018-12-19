/*
796. Rotate String

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate String.

Test Cases:
"clrwmpkwru"
"wmpkwruclr"
"abcde"
"cdeab"
""
""
*/

class Solution {
public:
    bool rotateString(string A, string B) {
        // KMP, O(m+n) time; if true, B must match copy of 2 As
        if(A.size()!=B.size())  return false;
        if(A.size()<1||B.size()<1)  return true;
        int i, t, rt;
        vector<int> vb(B.size(),-1);
        for( i=0, t=-1; i<B.size()-1; ){// build next array 
            if(t==-1||B[i]==B[t])   vb[++i]=++t;
            else    t=vb[t];// t<i guranteed 
        }
        
        for( i=0, t=0, rt=0; rt<2; ){
            if(t==-1||A[i]==B[t]){
                i++;
                t++;
            }else{
                t=vb[t];
            }
            if(t==B.size()) return true;
            if(i==A.size()){
                i=0;
                rt++;
            }
        }
        
        return false;
    }
};