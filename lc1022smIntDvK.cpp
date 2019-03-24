/*
1022. Smallest Integer Divisible by K

Test Cases:
1
2
3
17

Runtime: 36 ms
Memory Usage: 15.3 MB

https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/261226/
*/

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        // DP, math; K in [1,10^5]
        int len, r;
        unordered_set<int> um;
        
        for( len=1, r=1%K; ; len++){
            if(r==0)    return len;
            
            if(um.find(r)!=um.end())    return -1;
            else    um.emplace(r);
            
            r=(10*r+1)%K;
        }
        
        return -1;
    }
};