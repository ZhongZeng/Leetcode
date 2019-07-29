/*
Ranking of Weekly Contest 147  
Rank	Name	Score	Finish Time 	Q1 (2)	Q2 (5)	Q3 (7)	Q4 (7)
833 / 4906	zhongzeng 	14	1:20:25	 0:03:49	 0:20:10  1	 1:05:25  2	

1137. N-th Tribonacci Number

Test Cases:
0
1
2
4
25

Runtime: 0 ms
Memory Usage: 8.1 MB
*/

class Solution {
public:
    int tribonacci(int n) {
        // brute force, O(n) time
        if(n==0)    return 0;
        else if(n<=2)   return 1;
        int a=0, b=1, c=1, d;
        for( int i=3; i<=n; i++){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return c;
    }
};