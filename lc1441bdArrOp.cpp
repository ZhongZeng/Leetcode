/*
1441. Build an Array With Stack Operations

Ranking of Weekly Contest 188  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
2278 / 12714	zhongzeng 	12	1:11:58	 0:04:05	 1:11:58	 0:29:48

Company	Google
Related Topics	Stack

Test Cases:
[1,3]
3
[1,2,3]
3
[1,2]
4
[2,3,4]
4

Runtime: 8 ms
Memory Usage: 8.1 MB
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        for( int i=0, j=1; i<target.size(); j++){
            ops.push_back("Push");
            if(target[i]!=j)    ops.push_back("Pop");
            else    i++;
        }
        return ops;
    }
};