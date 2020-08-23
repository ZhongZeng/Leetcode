/*
1560. Most Visited Sector in a Circular Track

Weekly Contest 203
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (6)	Q4 (7)
1691 / 15080	zhongzeng 	13	1:09:11	 0:18:04  1	 1:04:11	 0:53:02	

Easy
Companies	Expedia
Related Topics	Array

Test Cases:
3
[3,2,1,2,1,3,2,1,2,1,3,2,3,1]
4
[1,3,1,2]
2
[2,1,2,1,2,1,2,1,2]
7
[1,3,5,7]

Runtime: 12 ms	Your runtime beats 16.67 % of cpp submissions.
Memory Usage: 11.2 MB
*/

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        // O(n) time
        vector<int> rt;
        if(rounds[0]<rounds.back()){
            for( int i=rounds[0]; i<=rounds.back(); i++)
                rt.push_back(i);
        }else if(rounds.back()<rounds[0]){
            for( int i=1; i<=rounds.back(); i++)
                rt.push_back(i);
            for( int i=rounds[0]; i<=n; i++)
                rt.push_back(i);
        }else{
            rt={rounds[0]};
        }
        
        return rt;
    }
};