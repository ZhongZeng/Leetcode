/*
1200. Minimum Absolute Difference

Companies   
Audible
Related Topics 
Array

Test Case:
[4,2,1,3]
[1,3,6,10,15]

Runtime: 116 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 16.9 MB
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> rt;
        sort(arr.begin(), arr.end());
        int mn=arr[1]-arr[0];
        for( int i=1; i<arr.size(); i++){
            if(arr[i]-arr[i-1]<mn)  mn=arr[i]-arr[i-1];
        }
        for( int i=1; i<arr.size(); i++){
            if(arr[i]-arr[i-1]==mn) rt.push_back({arr[i-1],arr[i]});
        }
        return rt;
    }
};