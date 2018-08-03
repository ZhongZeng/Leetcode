
/*
Leetcode 709. To Lower Case

Companies  

Related Topics 
String 

Test Case:
"Hello"

Next challenges: Word Ladder II, Mini Parser, Word Abbreviation

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    string toLowerCase(string str) {
        
        for( int i=0, t; i<str.size(); i++){
            t=str[i]-'A';
            if(-1<t&&t<27)  str[i]=str[i]+32;
        }
        
        return str;
    }
};
