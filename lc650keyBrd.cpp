
/*
Leetcode 650. 2 Keys Keyboard

Related Topics 
Dynamic Programming 
Similar Questions 
4 Keys Keyboard 
Next challenges: 4 Keys Keyboard

Runtime: 3 ms
You are here! 
Your runtime beats 61.30 % of cpp submissions.

*/

class Solution {
public:
    int minSteps(int n) {
        // the answer is the sum of prime factors of n
        int sum=0, c=2;
        while( n!=1 ){
            while( n%c==0 ){
                n = n/c;
                sum += c;
            }
            c++;
        }
        return sum;
    }
};
