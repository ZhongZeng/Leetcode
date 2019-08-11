/*
Ranking of Weekly Contest 149  
Rank	Name	Score	Finish Time 	Q1 (4)	Q2 (5)	Q3 (6)	Q4 (9)
823 / 5091	zhongzeng 	15	1:35:02	 0:11:45  1	 0:43:07	 1:25:02  1	

1154. Day of the Year

Test Cases:
"2019-01-09"
"2019-02-10"
"2003-03-01"
"2004-03-01"
"2016-02-29"

Runtime: 0 ms
Memory Usage: 8.3 MB
*/

class Solution {
public:
    int dayOfYear(string date) {
        int year=str2num(date,0,4), month=str2num(date,5,7), day=str2num(date,8,10);
        vector<int> vc={0,0,31,59,90,120,151,181,212,243,273,304,334};// vc.size()==12; previous months
        return vc[month]+day+(2<month&&((year%100!=0&&year%4==0)||year%400==0));// Feb 28|29 
    }
    
protected:
    int str2num(string str, int b, int e){// [b,e)
        int num=0;
        for( int i=b; i<e; i++) num=num*10+str[i]-'0';
        return num;
    }
};