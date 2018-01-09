

/*
Leetcode 371. Sum of Two Integers

Related Topics 
Bit Manipulation
Similar Questions 
Add Two Numbers

Next challenges: Subsets, Binary Watch, 
Minimum Unique Word Abbreviation

Test Cases:
1
2
7
5
4
8
-2
-4
-1
-11
-3
-8

Runtime: 3 ms
Your runtime beats 2.75 % of cpp submissions.

*/


class Solution {
public:
    int getSum(int a, int b) {
	// I wasn't sure about negative #s, but it AC'ed. 
        int c, d;
        c=a^b;
        d=(a&b)<<1;
        while(d!=0){
            c=a^b;
            d=(a&b)<<1;
            a=c;
            b=d;
        }
        
        return c;
    }
};
