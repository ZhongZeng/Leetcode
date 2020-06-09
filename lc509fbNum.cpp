/*
509. Fibonacci Number

Easy
Companies	Amazon, Apple, Facebook, Microsoft
Related Topics	Array

Test Cases:
2
3
4

Runtime: 4 ms, faster than 31.49% of C++ online submissions for Fibonacci Number.
Memory Usage: 5.9 MB, less than 85.08% of C++ online submissions for Fibonacci Number.
Next challenges: Find K-th Smallest Pair Distance, Pancake Sorting,
Compare Strings by Frequency of the Smallest Character
*/


class Solution {
public:
    int fib(int N) {
        if(N<1) return 0;
        if(N<3) return 1;
        int a=1, b=1, c;
        for( int i=2; i<N; i++){
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};