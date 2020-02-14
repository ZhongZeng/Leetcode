/*
1346. Check If N and Its Double Exist

Company	Google
Related Topics	Array

Test Cases:
[10,2,5,3]
[7,1,14,11]
[3,1,7,11]
[-2,0,10,-19,4,6,-8]

Runtime: 8 ms, faster than 78.02% of C++ online submissions for Check If N and Its Double Exist.
Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Check If N and Its Double Exist.

Next challenges:
Minimum Swaps to Group All 1's Together, Smallest String With Swaps, 
Remove Sub-Folders from the Filesystem
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Hash Table, O(n) time
        int t=0;
        unordered_set<int> us;
        
        for( int i=0; i<arr.size(); i++)    us.emplace(arr[i]);
        
        for( int i=0; i<arr.size(); i++){
            if(arr[i]!=0&&us.find(arr[i]*2)!=us.end())  return true;
        }
        
        for( int i=0; i<arr.size(); i++){
            if(arr[i]==0)   t++;
        }
        
        return 1<t;
    }
};