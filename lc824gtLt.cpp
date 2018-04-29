
/*
Leetcode 824. Goat Latin

Test Cases:
"I speak Goat Latin"
"The quick brown fox jumped over the lazy dog"

5 ms

*/

class Solution {
public:
    string toGoatLatin(string S) {
		// O(n) time 
        int a=1;
        char c;
        string rt;
        
        for(int i=0; i<S.size(); ){
            if(S[i]==' '){
                rt.push_back(' ');
                i++;
            }else{
                if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u'||
                   S[i]=='A'||S[i]=='E'||S[i]=='I'||S[i]=='O'||S[i]=='U'){
                    for( ; i<S.size()&&S[i]!=' '; i++)  rt.push_back(S[i]);
                }else{
                    c=S[i++];
                    for( ; i<S.size()&&S[i]!=' '; i++)  rt.push_back(S[i]);
                    rt.push_back(c);
                }
                rt.append("ma");
                for(int j=0; j<a; j++)  rt.push_back('a');
                a++;                
            } 
        }
        
        return rt;
    }
};
