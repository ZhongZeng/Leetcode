/*
1029. Two City Scheduling

Companies	Bloomberg
Related Topics	Greedy

Test Cases:
[[10,20],[30,200],[400,50],[30,20]]

Runtime: 8 ms
Memory Usage: 9.2 MB

Ranking of Weekly Contest 133  
Rank		Name		Score	Finish Time 	Q1 (4)	Q2 (4)		Q3 (6)	Q4 (7)
121 / 4860	zhongzeng 	21		0:56:32	 		0:16:05	 0:21:00	 0:33:47	 0:56:32
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort; Bloomberg
        int sum=0;
        vector<int> vd;
        for( int i=0; i<costs.size(); i++)  sum+=costs[i][0];// assuming all people fly to city A
        for( int i=0; i<costs.size(); i++)  vd.push_back(costs[i][1]-costs[i][0]);
        
        sort(vd.begin(), vd.end());
        // change N people to fly to city B from A
        for( int i=0; i<(vd.size()>>1); i++)    sum+=vd[i];
        
        return sum;
    }
};