/*
1561. Maximum Number of Coins You Can Get

Medium
Related Topics	Sort

Test Cases:
[2,4,1,2,7,8]
[2,4,5]
[9,8,7,6,5,1,2,3,4]

Runtime: 372 ms	Your runtime beats 50.00 % of cpp submissions.
Memory Usage: 53.4 MB
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // O(n*log(n)) time; minmax 
        int my_coins=0;
        sort(piles.begin(), piles.end());
        for( int i=piles.size()/3; 0<i; i--){
            my_coins+=piles[piles.size()-2*i];
        }
        return my_coins;
    }
};