
/*
Leetcode 231. Power of Two

Tags: Math, Bit Manipulation
Similar Problems: (E) Number of 1 Bits (E) Power of Three (E) Power of Four
Next challenges: (E) Number of 1 Bits(E) Power of Three(E) Power of Four

You are here! 
Your runtime beats 37.77 % of cpp submissions.	3 ms

Test Case:
1
2
5
8
-8
Expected: false
-2147483648
Expected: false

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n<1 ? false : !(n & (n-1));
    }
};
