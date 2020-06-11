/*
1426. Counting Elements

Easy
Companies	DRW
Related Topics	Array

Test Cases:
[1,2,3]

Runtime: 4 ms	Your runtime beats 60.95 % of cpp submissions.
Memory Usage: 6.6 MB	Your memory usage beats 54.85 % of cpp submissions.
*/

class Solution {
public:
    int countElements(vector<int>& arr) {
        // hash table, O(n) time&space; sort, O(n*log(n)) time, O(n) space
        int sum=0;
        unordered_set<int> nums;
        for( int i=0; i<arr.size(); i++)
            nums.emplace(arr[i]);
        
        for( int i=0; i<arr.size(); i++){
            if(nums.find(arr[i]+1)!=nums.end()) sum++;
        }
        
        return sum;
    }
};