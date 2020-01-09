/*
1310. XOR Queries of a Subarray

Company	Airtel
Related Topics	Bit Manipulation

Test Cases:
[1,3,4,8]
[[0,1],[1,2],[0,3],[3,3]]
[4,8,2,10]
[[2,3],[1,3],[0,0],[0,3]]

Runtime: 136 ms	Your runtime beats 55.93 % of cpp submissions.
Memory Usage: 26.7 MB
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // O(n) time&space; bit manipulation; a^b^c=a^(b^c), # of 1s on each digit is odd or even; a^b=c <==> a=b^c; a^b=b^a 
        vector<int> rt, xr={0};// xr: XR of arr[0,i) 
        if(arr.size()<1)    return rt;
        for( int i=0; i<arr.size(); i++)    xr.push_back(xr.back()^arr[i]);
        
        for( int i=0; i<queries.size(); i++){
            rt.push_back(xr[queries[i][1]+1]^xr[queries[i][0]]);
        }
        
        return rt;
    }
};