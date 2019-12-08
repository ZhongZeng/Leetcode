/*
1281. Subtract the Product and Sum of Digits of an Integer

Ranking of Weekly Contest 166  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
1318 / 5585	zhongzeng 	12	0:41:49	 0:02:21	 0:11:25	 0:36:49  1	

Companies	Quora
Related Topics	Math

Test Cases:
234
4421

Runtime: 4 ms
Memory Usage: 8.1 MB
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int pd=1, sum=0;
        for( int m=n; 0<m; m=m/10){
            int d=m%10;
            pd*=d;
            sum+=d;
        }
        return pd-sum;
    }
};