/*
1550. Three Consecutive Odds

Ranking of Weekly Contest 202  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
1021 / 14374	zhongzeng 	13	1:04:24	 0:05:44  1	 0:16:12		 0:54:24  1

Easy
Companies	DJI
Related Topics	Array

Test Cases:
[2,6,4,1]
[1,2,34,3,4,5,7,23,12]

Runtime: 8 ms
Memory Usage: 8.2 MB
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        // O(n) time, O(1) space
        for( int i=2; i<arr.size(); i++){
            if(arr[i]%2==1&&(arr[i-1]%2==1)&&(arr[i-2]%2==1))    return true;
        }
        return false;
    }
};