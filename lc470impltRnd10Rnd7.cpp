

/*
Leetcode 470. Implement Rand10() Using Rand7()

Companies  

Related Topics 
Random, Rejection Sampling 

Test Cases:
1
2
3

Next challenges: Random Flip Matrix, Random Point in Non-overlapping Rectangles, 
Generate Random Point in a Circle

Runtime: 56 ms
Your runtime beats 79.28 % of cpp submissions.

*/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int rd1=rand7(), rd2=rand7(); 
		
		while(5<rd1)	rd1=rand7();// 1 to 5
		while(6<rd2)	rd2=rand7();// 1 to 6
		
		return rd2%2!=0?rd1*2:rd1*2-1;
    }
};
