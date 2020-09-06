/*
1578. Minimum Deletion Cost to Avoid Repeating Letters

Medium
Companies	Microsoft
Related Topics	Greedy

Test Cases:
"abaac"
[1,2,3,4,5]
"abc"
[1,2,3]
"aabaa"
[1,2,3,4,1]

Runtime: 512 ms
Memory Usage: 95.4 MB
*/

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        // Greedy; O(n) time 
        int total_cost=0, len;
        for( int i=0; i<s.size()-1; i=i+len){
            int sum=0, max=cost[i];
            for( len=0; i+len<s.size(); len++){
                if(s[i]!=s[i+len])  break;
            }
            if(len==1)  continue;
            for( int j=0; j<len; j++){
                max=max<cost[i+j]?cost[i+j]:max;
                sum+=cost[i+j];
            }
            total_cost+=sum-max;// delete all consecutive chars except the most costly one
        }
        return total_cost;
    }
};