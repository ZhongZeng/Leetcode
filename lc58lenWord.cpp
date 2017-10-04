

/*
Leetcode 58. Length of Last Word

Related Topics 
String 

Next challenges: Text Justification, Longest Uncommon Subsequence II, Palindromic Substrings

Test Cases:
"Hello World"
"Hello World "
"world"

Runtime: 3 ms
You are here! 
Your runtime beats 31.62 % of cpp submissions.


*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l=0, i=s.size();
        while( --i!=-1 ){
            if( s[i]!=' '){
                break;
            }
        }
        
        ++i;
        
        while( --i!=-1 ){
            if( s[i]!=' '){
                l++;
            }else{
                return l;
            }               
        }
                             
        return l; 
    }
};

