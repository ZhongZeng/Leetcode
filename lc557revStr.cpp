
/*
Leetcode 557. Reverse Words in a String III

Related Topics 
String 
Similar Questions 
Reverse String II 

Next challenges: Reverse String II

Test Case:
"Let's take LeetCode contest"

Runtime: 23 ms
Your runtime beats 43.66 % of cpp submissions.

*/


class Solution {
public:
    string reverseWords(string s) {
        if(s.size()<2)  return s;
        int i=0, j=0;
        while(++i!=s.size()){
            // In the string, each word is separated by single space and there will not be any extra space in the string.
            if(s[i]==' '){
                reverseStr(s, j, i-1);
                j=i+1;
            }
        }
        reverseStr(s, j, s.size()-1);
        
        return s;
    }

    void reverseStr(string & s, int b, int e){
        char c;
        for(;b<e;b++,e--){
            c=s[b];
            s[b]=s[e];
            s[e]=c;
        }
        return;
    }
    
};
