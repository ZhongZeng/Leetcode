/*
1186. Maximum Subarray Sum with One Deletion

Companies	Two Sigma
Related Topics	Dynamic Programming

Test Cases:
[1,-2,0,3]
[1,-2,-2,3]
[-1,-1,-1,-1]

Runtime: 40 ms, faster than 87.18% of C++ online submissions for Maximum Subarray Sum with One Deletion.
Memory Usage: 11.4 MB, less than 100.00% of C++ online submissions for Maximum Subarray Sum with One Deletion.
Next challenges: Longest Palindromic Subsequence, Largest Sum of Averages, Maximum Profit in Job Scheduling
*/

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // DP; including last ele w/ & w/t deletion
        // corner case {-1}
        if(arr.size()<1)    return 0;
        int max=arr[0], sum0=arr[0], sum1=0;
        
        for( int i=1; i<arr.size(); i++){
            int sum0t=arr[i]+(sum0<0?0:sum0), sum1t=sum0<sum1+arr[i]?sum1+arr[i]:sum0;
            sum0=sum0t;
            sum1=sum1t;
            if(max<sum0)    max=sum0;
            if(max<sum1)    max=sum1;
        }
        
        return max;
    }
};