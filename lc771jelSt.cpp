

/*
Leetcode 771. Jewels and Stones

Test Cases:
"aA"
"aAAbbbb"
"z"
""ZZ

Runtime: 12 ms

*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // hash_table
        int sum=0;
        unordered_set<char> us;
        unordered_set<char>::iterator usi;
        for(string::iterator it=J.begin(); it!=J.end(); it++){
            usi=us.find(*it);
            if(usi==us.end())   us.emplace(*it);
        }
        
        for(string::iterator it=S.begin(); it!=S.end(); it++){
            usi=us.find(*it);
            if(usi!=us.end())   sum++;
        }
        
        return sum;
    }
};
