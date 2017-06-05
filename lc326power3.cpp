

/*
Leetcode 326. Power of Three

Tag: Math
Next challenges: (E) Power of Four

You are here! 
Your runtime beats 48.79 % of cpp submissions.	59 ms
Your runtime beats 36.56 % of cpp submissions.	62 ms

Test Cases:
0
27
999

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
            if(n<1) return false;
            while(n!=1){
                if(n%3==0)  n=n/3;
                else return false;
            }
            return true;
    }
};
