/*
1456. Maximum Number of Vowels in a Substring of Given Length

Company	Amazon
Related Topics	String, Sliding Window

Test Cases:
"abciiidef"
3
"aeiou"
2
"leetcode"
3
"rhythms"
4
"tryhard"
4

Runtime: 100 ms
Memory Usage: 10.1 MB
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        // moving window, O(n) time; k in [1,s.size()]
        int vw=0, mx=0, i;
        for( i=0; i<k; i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')   vw++;
        }
        mx=vw;
        
        for( ; i<s.size(); i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')   vw++;
            if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u') vw--;
            if(mx<vw)   mx=vw;
        }
        return mx;
    }
};