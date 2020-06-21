/*
1486. XOR Operation in an Array

Ranking of Weekly Contest 194  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (5)	Q3 (6)	Q4 (7)
5469 / 13808	zhongzeng 	3	0:03:25	 0:03:25

Easy
Companies	Walmart Labs
Related Topics	Array, Bit Manipulation		

Test Cases:
5
0
4
3
1
7
10
5

Runtime: 0 ms
Memory Usage: 5.8 MB
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int x=start;
        for( int i=1; i<n; i++)
            x=x^(start+2*i);
        return x;
    }
};