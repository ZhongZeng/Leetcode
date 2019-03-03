/*
1003. Check If Word Is Valid After Substitutions

Related Topics:	Stack 

Test Cases:
"aabcbc"
"abcabcababcc"
"abccba"
"cababc"

*/

class Solution {
public:
    bool isValid(string S) {
        // array, stack; S[i] is 'a', 'b', or 'c'; X, Y must be valid
        vector<int> vc(2,0);
        
        for( int i=0; i<S.size(); i++){
            if(S[i]=='a'){// 'a'
                vc[0]+=1;
            }else if(S[i]=='b'){// 'b' matches previous 'a'
                if(vc[0]<1){
                    return false;
                }else{
                    vc[0]-=1;
                    vc[1]+=1;
                }
            }else{// 'c' matches previous 'b'
                if(vc[1]<1) return false;
                else    vc[1]-=1;
            }
        }
        
        return vc[0]==0&&vc[1]==0;
    }
};