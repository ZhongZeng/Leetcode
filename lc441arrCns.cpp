
/*
Leetcode 441. Arranging Coins

Companies 
GoDaddy 
Related Topics 
Math, Binary Search

Next challenges: Search in Rotated Sorted Array II, 
Russian Doll Envelopes, Swim in Rising Water

Test Cases:
5
8
100
1804289383

Runtime: 24 ms
Your runtime beats 65.09 % of cpp submissions.

*/

class Solution {
public:
    int arrangeCoins(int n) {
        // Binary search 
        if(n<2) return n;
        int b=0, e=n, mid;// [b,e)
        while(1<e-b){
            mid=b+(e-b)/2;
            if(n*1.0/mid<(1+mid)/2.0)   e=mid;
            else    b=mid;
        }
        return b;
    }
};
