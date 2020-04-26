/*
1423. Maximum Points You Can Obtain from Cards

Companies	Flipkart
Related Topics	Array, Dynamic Programming, Sliding Window

Test Cases:
[1,2,3,4,5,6,1]
3
[2,2,2]
2
[9,7,7,9,7,7,9]
7
[1,1000,1]
1
[1,79,80,1,1,1,200,1]
3

Runtime: 136 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 42.4 MB
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // array; O(k) time, O(1) space
        int sum=0, max=0;
        for( int i=0; i<k; i++) sum+=cardPoints[i];
        max=sum;
        for( int i=0; i<k; i++){
            sum=sum+cardPoints[cardPoints.size()-1-i]-cardPoints[k-1-i];
            if(max<sum) max=sum;
        }
        return max;
    }
};