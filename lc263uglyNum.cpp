
/*
Leetcode 263. Ugly Number

Difficulty:Easy
Category:Algorithms
Tag: Math
Next challenges: (E) Happy Number(E) Count Primes(M) Ugly Number II

You are here! 
Your runtime beats 36.09 % of cpp submissions.	3 ms

Test Cases:
-2147483648

*/

class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return false;
        
        num=div(num, 2);
        num=div(num, 3);
        num=div(num, 5);
        
        return num==1;
    }
    
protected:
    int div(int t, int f){
        while( t%f ==0 ){
            t=t/f;
        }
        return t;
    }
    
};
