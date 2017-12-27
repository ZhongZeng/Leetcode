

/*
Leetcode 343. Integer Break

Related Topics 
Math, Dynamic Programming

Next challenges: Best Meeting Point, 
Self Crossing, 4 Keys Keyboard

Test Cases:
2
3
4
5
10
11
12
13
57
58

Runtime: 0 ms
Your runtime beats 25.68 % of cpp submissions.

*/

class Solution {
public:
    int integerBreak(int n) {
        // O(n) times of multiplication
        // 3*3>2*2*2
        // You may assume that n is not less than 2 and not larger than 58
        // bit manipulation is faster
        if(n<4) return n-1;
        
        int i=4, pd=1, c2=2, c3=0;// #2, #3
        while(i++<n){
            if(c2!=0){
                c2--;
                c3++;
            }else{
                c2+=2;
                c3--;
            }
        }
        
        for(int j=0; j!=c3; j++)    pd*=3;
        pd=pd<<c2;
        
        return pd;
    }
};


/*
// Runtime: 3 ms
// Your runtime beats 1.87 % of cpp submissions.
class Solution {
public:
    int integerBreak(int n) {
        // O(n) times of multiplication
        // 3*3>2*2*2
        // You may assume that n is not less than 2 and not larger than 58
        if(n<4) return n-1;
        
        int i=4, pd=4, c2=2, c3=0;// #2, #3
        while(i++<n){
            if(c2!=0){
                c2--;
                c3++;
                pd=pd/2*3;// divide first to avoid overflow
            }else{
                c2+=2;
                c3--;
                pd=pd/3*4;
            }
        }
        return pd;
    }
};
*/