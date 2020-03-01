/*
1358. Number of Substrings Containing All Three Characters

Company	DE Shaw
Related Topics	String

Test Cases:
"abcabc"
"aaacb"
"abc"

Runtime: 28 ms, faster than 61.91% of C++ online submissions for Number of Substrings Containing All Three Characters.
Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Number of Substrings Containing All Three Characters.

Next challenges:
Split Concatenated Strings, Design Log Storage System
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        // 2-pointer 
        if(s.size()<3)  return 0;
        int sum=0, b=0, e=0; // [b,e]
        vector<int> vc(26,0);
        vc[s[0]-'a']+=1;
        
        while( true ){// substring starting @ b, ending @ & a/t e 
            if(0<vc[0]&&0<vc[1]&&0<vc[2]){
                sum+=s.size()-e;
                vc[s[b++]-'a']-=1;
            }else{
                if(e<s.size()-1)    vc[s[++e]-'a']+=1;
                else    return sum;
            }
        }
        
        return sum;
    }
};
/*
match => b++: no longer match: e++; still match: count substr [b,e to end], e++ 
no match => e++: match: count substr [b,e to end], e++; still no match: e++ 
*/