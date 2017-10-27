
/*
Leetcode 693. Binary Number with Alternating Bits


Related Topics 
Bit Manipulation 
Similar Questions 
Number of 1 Bits 

Next challenges: Number of 1 Bits

Test Cases:
1
4
5
7
10

Runtime: 3 ms
You are here! 
Your runtime beats 36.83 % of cpp submissions.


*/

class Solution {
public:
    bool hasAlternatingBits(int n) {        
        
        n = n>>1 ^ n; // this n+1 is power of 2               
        
        return n++ & n ? false : true ;
    }
};
