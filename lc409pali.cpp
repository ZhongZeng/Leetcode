
/*
Leetcode 409. Longest Palindrome

Related Topics 
Hash Table 
Similar Questions 
Palindrome Permutation 

Test Cases:
"abccccdd"
"ccd"
"ccc"

Runtime: 16 ms
You are here! 
Your runtime beats 0.43 % of cpp submissions

Runtime: 6 ms
You are here! 
Your runtime beats 24.47 % of cpp submissions.

*/

// Solution 1 
class Solution {
public:
    int longestPalindrome(string s) {
        int num=0;
        bool odd=false;
        unordered_map<char, int> um;
        unordered_map<char, int>::iterator umi;
        for(string::iterator si=s.begin(); si!=s.end(); si++){
            umi=um.find(*si);
            if( umi!=um.end() ){
                umi->second++;
            }else{
                um.emplace( *si, 1 );
            }            
        }
            
        umi = um.begin() ; 
        while( umi != um.end() ){
            num += umi->second / 2;
            if( umi->second%2 == 1 ) {
                odd= true;
                umi++;
                break;
            }
            umi++;
        }
        
        while( umi != um.end() ){
            num += umi->second / 2;
            umi++;
        }

        return num*2+odd;
    }
};

/*
//Solution 2: 

// Runtime: 9 ms
// You are here! 
// Your runtime beats 5.53 % of cpp submissions.

// Runtime: 6 ms
// You are here! 
// Your runtime beats 24.47 % of cpp submissions.

class Solution {
public:
    int longestPalindrome(string s) {
        int num=0;
        bool odd=false;
        unordered_map<char, int> um;
        unordered_map<char, int>::iterator umi;
        for(string::iterator si=s.begin(); si!=s.end(); si++){
            umi=um.find(*si);
            if( umi!=um.end() ){
                umi->second++;
            }else{
                um.emplace( *si, 1 );
            }            
        }
            
        umi = um.begin() ; 
        while( umi != um.end() ){
            num += umi->second / 2;
            if( umi->second%2 == 1 ) {
                odd= true;
            }
            umi++;
        }

        return num*2+odd;
    }
};

*/
