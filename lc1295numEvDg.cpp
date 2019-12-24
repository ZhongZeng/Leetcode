/*
1295. Find Numbers with Even Number of Digits

Ranking of Weekly Contest 168  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (6)	Q4 (7)
2187 / 5525	zhongzeng 	7	0:57:27	 0:02:51	 0:57:27		

Company:	Quora
Related Topics: Array 

Test Cases:
[12,345,2,6,7896]
[555,901,482,1771]

Runtime: 8 ms	Your runtime beats 73.85 % of cpp submissions.
Memory Usage: 8.9 MB
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int sum=0;
        for( int i=0; i<nums.size(); i++)   sum+=evenDigits(nums[i])?1:0;
        return sum;
    }
    
protected:
    int evenDigits(int n){
        int d=0;
        for( int t=n; 0<n; n=n/10)  d++;
        return d%2==0;
    }
};