/*
1461. Check If a String Contains All Binary Codes of Size K

Medium
Companies	Google
Related Topics	String, Bit Manipulation

Test Cases:
"011101100101110101101000011111101011111101110100111100010000010110010010011100110001110010101101011010010001101111000111110000001010100101111001111010110001111011001110100010001111000111010001111100101011100001001011101100010101010110001011110101001101001001111101000100011101110100100100101101110000000110001011100100111111001000100100010011001000101101100010010010001111010111010011110111110001010100000110000111010110001100100110111000111010111000010100100100101011001111010110010101110101000011011101000110001001100111100011000100110010101100001111000100101001111001100001010100100100110100101100111000110010110101010110010110001111010110101111011011100111001010101001011000101101110100001110011110001011000011100011111001110011111101110001110010000111010011110001011010100101110010110110100011111011110010100011111000000001011100110000010101110110111"
7
"00110110"
2
"00110"
2
"0110"
1
"0110"
2
"0000000001011100"
4

Runtime: 812 ms, faster than 42.74% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
Memory Usage: 104 MB, less than 5.00% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
Next challenges: Simplify Path, Before and After Puzzle,
Smallest Subsequence of Distinct Characters
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // O(s+2**k) time; String, Hash Table; k in [1,20]
        int num=0, t=pow(2,k-1);
        unordered_set<int> us;
        
        for( int i=0; i<s.size()&&i<k; i++) num=(num<<1)+s[i]-'0';
        us.emplace(num);
        for( int i=k; i<s.size(); i++){
            num-=s[i-k]=='1'?t:0;
            num=num<<1;
            num+=s[i]-'0';
            us.emplace(num);
        }
        
        for( int i=(t<<1)-1; -1<i; i--)
            if(us.find(i)==us.end())    return false;
        
        return true;
    }
};