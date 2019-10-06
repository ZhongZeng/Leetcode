/*
1217. Play with Chips

Ranking of Weekly Contest 157  
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (6)
717 / 6650	zhongzeng 	18	1:13:25	 0:04:12	 0:19:09  2	 0:39:20	 1:03:25

Companies	Morgan Stanley 
Related Topics	Array, Math, Greedy

Test Cases:
[1,2,3]
[2,2,2,3,3]

Runtime: 4 ms
Memory Usage: 8.5 MB
*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd=0, even=0;
        for( int i=0; i<chips.size(); i++){
            if(chips[i]%2==0)   even+=1;
            else    odd+=1;
        }
        return odd<even?odd:even;
    }
};