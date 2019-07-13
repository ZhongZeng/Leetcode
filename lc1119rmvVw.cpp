/*
1119. Remove Vowels from a String

Companies	Amazon
Related Topics	String, Two Pointer
Similar Questions	Reverse Vowels of a String

Test Cases:
"leetcodeisacommunityforcoders"
"aeiou"

Runtime: 0 ms
Memory Usage: 8.6 MB
*/

class Solution {
public:
    string removeVowels(string S) {
        // O(n) time; O(1) space; 2-pointer; S contains lowercase only
        int i, j;
        for( i=0, j=0; j<S.size(); j++){
            if(S[j]!='a'&&S[j]!='e'&&S[j]!='i'&&S[j]!='o'&&S[j]!='u')   S[i++]=S[j];
        }
        
        S.erase( i, S.size()-i);
        
        return S;
    }
};