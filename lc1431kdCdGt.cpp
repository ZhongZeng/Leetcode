/*
1431. Kids With the Greatest Number of Candies

Easy
Related Topics	Array

Runtime: 4 ms, faster than 87.66% of C++ online submissions for Kids With the Greatest Number of Candies.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Kids With the Greatest Number of Candies.
Next challenges: Sum of Subsequence Widths, Reverse Subarray To Maximize Array Value,
Rank Transform of an Array
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Array; O(n) time
        int mx=candies[0];
        vector<bool> mst;
        for( int i=0; i<candies.size(); i++)
            mx=mx<candies[i]?candies[i]:mx;
        for( int i=0; i<candies.size(); i++)
            mst.push_back(candies[i]+extraCandies<mx?0:1);
        return mst;
    }
};