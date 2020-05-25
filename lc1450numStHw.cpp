/*
1450. Number of Students Doing Homework at a Given Time

Related Topics	Array

Test Cases:
[1,2,3]
[3,2,7]
4
[4]
[4]
4
[4]
[4]
5
[1,1,1,1]
[1,3,2,4]
7
[9,8,7,6,5,4,3,2,1]
[10,10,10,10,10,10,10,10,10]
5

Runtime: 8 ms	Your runtime beats 62.56 % of cpp submissions.
Memory Usage: 11.3 MB
*/

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        // O(n) time, O(1) space
        int sum=0;
        for( int i=0; i<startTime.size(); i++){
            if(startTime[i]<=queryTime&&queryTime<=endTime[i])  sum++;
        }
        return sum;
    }
};