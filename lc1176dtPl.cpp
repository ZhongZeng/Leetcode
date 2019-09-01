/*
1176. Diet Plan Performance

Companies	Amazon
Related Topics	Array, Sliding Window 

Test Cases:
[6,13,8,7,10,1,12,11]
6
5
37
[1,2,3,4,5]
1
3
3
[3,2]
2
0
1
[6,5,0,0]
2
1
5

Runtime: 40 ms	Your runtime beats 63.64 % of cpp submissions.
Memory Usage: 13.2 MB

*/

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		// O(n) time 
        int points=0, sum=0, i;
        for( i=0; i<k&&i<calories.size(); i++)  sum+=calories[i];
        if(sum<lower)   points-=1;
        else if(upper<sum)  points+=1;
        
        for( ; i<calories.size(); i++){
            sum=sum+calories[i]-calories[i-k];
            if(sum<lower)   points-=1;
            else if(upper<sum)  points+=1;
        }
        
        return points;
    }
};