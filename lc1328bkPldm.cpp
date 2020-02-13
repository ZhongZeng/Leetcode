/*
1328. Break a Palindrome

Company	VMWare
Related Topics	String 

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Break a Palindrome.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Break a Palindrome.

Next challenges:
Simplify Path, Find the Closest Palindrome, Single-Row Keyboard
*/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()<2) return "";
        
        for( int i=0; i<palindrome.size()/2; i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        
        palindrome.back()='b';
        
        return palindrome;
    }
};