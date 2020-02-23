/*
1360. Number of Days Between Two Dates

Ranking of Weekly Contest 177  
Rank	Name	Score	Finish Time 	Q1 (4)	Q2 (5)	Q3 (5)	Q4 (6)
2295 / 9091	zhongzeng 	14	1:12:15	 0:37:46	 1:12:15	 0:50:52

Test Cases:
"2019-06-29"
"2019-06-30"
"2020-01-15"
"2019-12-31"

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 8.4 MB
*/

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        // year in [1971,2100]
        int year1=extractNumber(date1,0,4), month1=extractNumber(date1,5,7), day1=extractNumber(date1,8,10),
            year2=extractNumber(date2,0,4), month2=extractNumber(date2,5,7), day2=extractNumber(date2,8,10),
            days=0;
        
        if(year2<year1) return daysBetweenDates(date2, date1);
        if(year2==year1&&month2<month1) return daysBetweenDates(date2, date1);
        if(year2==year1&&month2==month1&&day2<day1) return daysBetweenDates(date2, date1);
        
        // days in year1
        days-=daysFromYearBegin( year1, month1, day1);
        // days in year2
        days+=daysFromYearBegin( year2, month2, day2);
        // days in [year1,year2)
        days+=daysInYears( year1, year2);
        
        return days;
    }
    
protected:
    int extractNumber( string & date, int b, int e){// convert string to int for date[b,e) 
        int num=0;
        for( int i=b; i<e; i++) num=num*10+date[i]-'0';
        return num;
    }
    
    bool isLeapYear(int year){
        if(year%100==0) return year%400==0;
        else    return year%4==0;
    }
    
    int daysFromYearBegin( int year, int month, int day){
        int feb=2<month&&isLeapYear(year)?1:0;
        vector<int> monthly_days={0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};// 365
        return monthly_days[month]+day+feb;
    }
    
    int daysInYears( int year1, int year2){
        int days=(year2-year1)*365;// excluding feb 29
        days+=(year2-1)/4-(year1-1)/4;// feb 29
        return days;
    }
};