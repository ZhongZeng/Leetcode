
/*
Leetcode 266. Palindrome Permutation


Companies 
Google, Bloomberg, Uber
Related Topics 
Hash Table 
Similar Questions 
Longest Palindromic Substring, Valid Anagram, 
Palindrome Permutation II, Longest Palindrome

Next challenges: Longest Palindromic Substring, Palindrome Permutation II

Test Cases:
"aab"
"aaab"
""

Runtime: 2 ms
Your runtime beats 16.22 % of cpp submissions.

*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.size()<1)   return true;
        unordered_map<char,int> um;
        unordered_map<char,int>::iterator umi;
        bool b=false;
        for(int i=0; i<s.size(); i++){
            umi=um.find(s[i]);
            if(umi!=um.end())   umi->second+=1;
            else    um.emplace(s[i],1);
        }
        
        for(umi=um.begin(); umi!=um.end(); umi++){
            if(umi->second%2!=0){
                if(b)   return false;
                else    b=true;
            }
        }
        
        return true;
    }
};
