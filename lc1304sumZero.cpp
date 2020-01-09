/*
1304. Find N Unique Integers Sum up to Zero

Ranking of Weekly Contest 169  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
2480 / 5933	zhongzeng 	12	1:07:48	 0:03:28	 0:41:16	 0:57:48  2	

Company	Microsoft
Related Topics	Array

Runtime: 4 ms	Your runtime beats 98.69 % of cpp submissions.
Memory Usage: 8.7 MB

Test Cases:
5
[-7,-1,1,3,4]
3
[-1,0,1]
1
[0]
*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> vc;
        if(n%2==1)  vc.push_back(0);
        for( int i=0; i<(n>>1); i++){
            vc.push_back(i+1);
            vc.push_back(-i-1);
        }
        return vc;
    }
};