/*
1395. Count Number of Teams

Companies	Amazon
Related Topics	Array; Dynamic Programming (suggested)

Test Cases:
[2,5,3,4,1]
[2,1,3]
[1,2,3,4]

Runtime: 16 ms
Memory Usage: 8.1 MB

https://leetcode.com/problems/count-number-of-teams/discuss/555787/C%2B%2B-DP-20-Line-O(n*n)-Time-O(n)-Space
*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        // Dynamic Programming; O(n*n) time, O(n) space
        int sum=0;
        vector<vector<int>> teams;
        
        for( int i=0; i<rating.size(); i++){
            vector<int> vc={0,0};// # of groups of 2 for ascending and descending 
            for( int j=0; j<i; j++){
                if(rating[j]<rating[i]){
                    vc[0]+=1;
                    sum+=teams[j][0];
                }else if(rating[i]<rating[j]){
                    vc[1]+=1;
                    sum+=teams[j][1];
                }
            }
            teams.push_back(vc);
        }
        
        return sum;
    }
};