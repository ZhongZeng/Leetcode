/*
1562. Find Latest Group of Size M

Medium
Companies	Google
Related Topics	Binary Search

Test Cases:
[3,5,1,2,4]
1
[3,1,5,4,2]
2
[1]
1
[2,1]
2

Runtime: 580 ms	Your runtime beats 40.00 % of cpp submissions.
Memory Usage: 82.7 MB

https://leetcode.com/problems/find-latest-group-of-size-m/discuss/807083/C++-O(n)-Time-Record-Length-at-Each-Element-and-Their-Counts
*/

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        // O(n) time, array; m>0
        int latest=-1;
        vector<int> lens(arr.size()+2, 0), counts(arr.size()+2,0);// +2 to avoid checking on boundaries
        
        for( int i=0; i<arr.size(); i++){
            int len=1, len_prev=lens[arr[i]-1], len_next=lens[arr[i]+1];
            len+=lens[arr[i]-1];
            len+=lens[arr[i]+1];
            
            lens[arr[i]-len_prev]=len;
            lens[arr[i]+len_next]=len;
            
            counts[len_prev]-=1;
            counts[len_next]-=1;
            counts[len]+=1;
            
            if(len==m)  latest=i+1;// this step
            if(len_prev==m&&counts[len_prev]==0) latest=i;// previous step
            if(len_next==m&&counts[len_next]==0) latest=i;// previous step
        }
        
        return latest;
    }
};