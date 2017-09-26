
/*

Leetcode 680. Valid Palindrome II

Related Topics 
String 
Similar Questions 
Valid Palindrome 

Test Cases:
"abc"
"aba"

Runtime: 129 ms
You are here! 
Your runtime beats 38.53 % of cpp submissions.

*/


class Solution {
public:
    bool validPalindrome(string s) {
        return validPal( s.begin(), s.end()-1, false);        
    }
    
protected:
    bool validPal( string::iterator b, string::iterator e, bool d ){
        while( b<e ){
            // cout<<*b<<' '<<*e<<endl; 
            if( *b != *e ){
                if( d ){
                    return false; 
                }else{         
                    return validPal( b+1, e, true) || validPal( b, e-1, true) ; 
                }                
            }
            b++;
            e--;    
        }
        return true; 
    }
    
};
