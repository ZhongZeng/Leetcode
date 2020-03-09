/*
1374. Generate a String With Characters That Have Odd Counts

Ranking of Weekly Contest 179  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
985 / 6242	zhongzeng 	18	1:34:39	 0:04:02	 0:15:13	 0:33:31	 1:24:39  2

Related Topcis	String 

Test Cases:
4
7

Runtime: 0 ms
Memory Usage: 7.9 MB

https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/discuss/532753/on-naive-solution
*/

class Solution {
public:
    string generateTheString(int n) {
        if(n%2==1){
            string str(n, 'a');
            return str;
        }else{
            string str(n-1, 'a');
            str.push_back('b');
            return str;
        }
    }
};