

/*
Leetcode 541. Reverse String II

Related Topics 
String 
Similar Questions 
Reverse String, Reverse Words in a String III 

Next challenges: One Edit Distance, 
Word Abbreviation, Count Different Palindromic Subsequences

Test Cases:
"abcdefg"
3
"abcdefg"
2

Runtime: 9 ms
Your runtime beats 13.37 % of cpp submissions.

*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int m=s.size()/(2*k), n=-1, i=0;
        char c;
        while(++n!=m){
            for(int b=i, e=i+k-1; b<e; b++, e--){
                c=s[b];
                s[b]=s[e];
                s[e]=c;
                //cout<<s[b]<<"-"<<s[e]<<" ";
            }
            i+=2*k;
        }
        
        for(int b=i,e=s.size()<i+k?s.size()-1:b+k-1; b<e; b++, e--){
            c=s[b];
            s[b]=s[e];
            s[e]=c;
            //cout<<s[b]<<"-"<<s[e]<<" ";           
        }
        
        return s;
    }
};
