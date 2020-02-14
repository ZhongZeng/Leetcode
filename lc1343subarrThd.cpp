/*
1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

Company	LinkedIn
Related Topics	Array

Runtime: 116 ms, faster than 89.34% of C++ online submissions for Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold.
Memory Usage: 16.4 MB, less than 100.00% of C++ online submissions for Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold.

Next Challenges:
Compare Strings by Frequency of the Smallest Character, Day of the Week, 
Reduce Array Size to The Half
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // array, moving window
        int sum=0, t=0;
        threshold=threshold*k;
        
        for( int i=0; i<k; i++) t+=arr[i];
        if(threshold<=t)    sum++;
        
        for( int i=k; i<arr.size(); i++){
            t=t+arr[i]-arr[i-k];
            if(threshold<=t)    sum++;
        }
        
        return sum;
    }
};