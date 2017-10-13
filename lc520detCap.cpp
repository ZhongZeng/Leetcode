

/*
Leetcode 520. Detect Capital

Related Topics 
String 

Next challenges: Multiply StringsPalindrome PairsWord Abbreviation

Test Cases:
"USA"
"FlaG"
"sadea"
"a"
"A"

Runtime: 9 ms
You are here! 
Your runtime beats 31.67 % of cpp submissions. 

*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        string::iterator it=word.begin();
        if( -1<*it -'a' ){ // 1st letter is not capital
            while( ++it!=word.end() ){ // remaining shouldn't be capital
                if( *it-'a'<0 )    return false;                
            }                
        }else if( ++it!=word.end() ){ // 1st letter is capital
            if( -1<*it-'a' ){ // 2nd letter is not capital
                while( ++it!=word.end() ){ // remaining shouldn't be capital
                    if( *it-'a'<0 )    return false;
                }                               
            }else{ // 2nd letter is capital
                while( ++it!=word.end() ){ // remaining should be capitals
                    if( -1<*it-'a' )    return false;                
                }                                
            }            
        }
        
        return true;
    }
};

