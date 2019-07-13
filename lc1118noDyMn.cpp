/*
1118. Number of Days in a Month

Ranking of Biweekly Contest 4  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (3)	Q3 (5)	Q4 (6)
680 / 1622	zhongzeng 	11	0:34:34	 0:07:59	 0:16:03	 0:29:34  1	

Companies	Amazon

Test Cases:
1992
7
1992
5
2000
2
1900
2

Runtime: 0 ms
Memory Usage: 8.3 MB

*/

class Solution {
public:
    int numberOfDays(int Y, int M) {
        if(M==2)    return (Y%4==0&&(Y%100!=0||Y%400==0))?29:28;
        else if(M<8)    return M%2==0?30:31;
        else    return M%2==1?30:31;
    }
};