

/*
Leetcode 495. Teemo Attacking

Related Topics 
Array
Similar Questions 
Merge IntervalsCan Place FlowersDota2 Senate

Next challenges: Merge IntervalsDota2 Senate

Test Cases:
[1,4]
2
[1,2]
2
[1,2,3,4,5,6,7,8,9]
1
[1,2,3,4,5,6,7,8,9]
5
[1,3,5,7,9,11,13,15]
3

Runtime: 79 ms
Your runtime beats 8.60 % of cpp submissions.

*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // O(n) time
        if(timeSeries.size()<1) return 0;
        int ps=duration;
        for(int i=1; i!=timeSeries.size(); i++){
            if(duration<timeSeries[i]-timeSeries[i-1]){
                ps+=duration;
            }else{
                ps+=timeSeries[i]-timeSeries[i-1];
            }
        }
        
        return ps;
    }
};

