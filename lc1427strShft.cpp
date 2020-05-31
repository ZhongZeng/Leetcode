/*
1427. Perform String Shifts

Test Cases:
"abc"
[[0,1],[1,2]]
"abcdefg"
[[1,1],[1,1],[0,2],[1,3]]
"yisxjwry"
[[1,8],[1,4],[1,3],[1,6],[0,6],[1,4],[0,2],[0,1]]

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Perform String Shifts.
Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Perform String Shifts.

Next challenges: Invalid Transactions, Queens That Can Attack the King,
Number of Burgers with No Waste of Ingredients
*/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        // String, Array; O(m+n) time
        string str;
        int left=0;
        for( int i=0; i<shift.size(); i++)  left+=shift[i][0]==0?shift[i][1]:-shift[i][1];

        left=left%((int)s.size());
        if(left<0)  left=left+s.size();
        
        for( int i=left; i<s.size(); i++)   str.push_back(s[i]);
        for( int i=0; i<left; i++)  str.push_back(s[i]);

        return str;
    }
};