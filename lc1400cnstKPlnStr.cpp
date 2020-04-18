/*
1400. Construct K Palindrome Strings

Companies	Uber
Related Topics	Greedy

Test Cases:
"cr"
7
"annabelle"
2
"leetcode"
3
"true"
4

Runtime: 168 ms, faster than 9.23% of C++ online submissions for Construct K Palindrome Strings.
Memory Usage: 12 MB, less than 100.00% of C++ online submissions for Construct K Palindrome Strings.
Next challenges: Create Maximum Number, Three Equal Parts, 
How Many Apples Can You Put into the Basket
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        // greedy, odd-count char to form palindrome, even-count char fit anywhere
        int odd=0, even=0;
        unordered_map<char,int> counts;
        for( int i=0; i<s.size(); i++){
            unordered_map<char,int>::iterator it=counts.find(s[i]);
            if(it!=counts.end())    it->second+=1;
            else    counts.emplace(s[i], 1);
        }
        
        for( unordered_map<char,int>::iterator it=counts.begin(); it!=counts.end(); it++){
            if(it->second%2==0) even++;
            else    odd++;
        }
        
        if(k<odd)   return false;// odd-1 palindrome strings of odd char
        
        return true;
    }
};