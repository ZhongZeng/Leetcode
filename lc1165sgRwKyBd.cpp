/*
1165. Single-Row Keyboard

Easy
Companies	Google
Related Topics	String

Test Cases:
"abcdefghijklmnopqrstuvwxyz"
"cba"

Runtime: 16 ms, faster than 51.57% of C++ online submissions for Single-Row Keyboard.
Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Single-Row Keyboard.
Next challenges: Remove Sub-Folders from the Filesystem, Replace the Substring for Balanced String,
Maximum Number of Occurrences of a Substring
*/

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        // O(n) time; Hash Table
        if(word.size()<1)   return 0;
        int sum=0;
        unordered_map<char,int> bd;
        for( int i=0; i<keyboard.size(); i++)
            bd[keyboard[i]]=i;
        sum+=bd[word[0]];
        for( int i=1; i<word.size(); i++)
            sum+=abs(bd[word[i]]-bd[word[i-1]]);
        return sum;
    }
};