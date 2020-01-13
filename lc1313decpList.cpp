/*
1313. Decompress Run-Length Encoded List

Company	Google
Related Topics	Array 

Test Case:
[1,2,3,4]

Runtime: 48 ms, faster than 37.50% of C++ online submissions for Decompress Run-Length Encoded List.
Memory Usage: 10.7 MB, less than 100.00% of C++ online submissions for Decompress Run-Length Encoded List.

Next challenges: Sum of Subsequence Widths,
Check If a Number Is Majority Element in a Sorted Array, Shift 2D Grid
*/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        // O(n) time&space
        vector<int> rt;
        for( int i=0; i<nums.size(); i+=2){
            for( int j=0; j<nums[i]; j++){
                rt.push_back(nums[i+1]);
            }
        }
        return rt;
    }
};