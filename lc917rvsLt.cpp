
/*
Leetcode 917. Reverse Only Letters

Test Cases:
"ab-cd"
"a-bC-dEf-ghIj"
"Test1ng-Leet=code-Q!"

Runtime: 0 ms

*/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        // 2-pointer
        char c;
        
        for( int b=0, e=S.size()-1; b<e; b++, e--){
            while(b<e&&!isLetter(S[b])) b++;
            while(b<e&&!isLetter(S[e])) e--;
            c=S[b];
            S[b]=S[e];
            S[e]=c;
        }
        
        return S;
    }
    
    bool isLetter(char & c){
        int t=c-'A';
        return (-1<t&&t<26)||(31<t&&t<58);
    }
};
