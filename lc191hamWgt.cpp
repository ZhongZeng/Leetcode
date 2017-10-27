

/*
Leetcode 191. Number of 1 Bits

Related Topics 
Bit Manipulation 
Similar Questions 
Reverse Bits, Power of Two, Counting Bits, Binary Watch, Hamming Distance, 
Binary Number with Alternating Bits 

Next challenges: Reverse Bits, Counting Bits, Binary Number with Alternating Bits

Runtime: 3 ms
You are here! 
Your runtime beats 26.00 % of cpp submissions.

*/


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum=0;
        while(n!=0){
            sum+=n-(n>>1<<1);
            n=n>>1;
        }
        return sum;
    }
};

