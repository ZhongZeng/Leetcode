
/*
Leetcode 201. Bitwise AND of Numbers Range

Related Topics 
Bit Manipulation

Next challenges: Single Number III, Number Complement, IP to CIDR

Test Cases:
5
7
8
18
11
13
4
5

Runtime: 45 ms
Your runtime beats 19.59 % of cpp submissions.

*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // any diff digits should be 0
        int d=n^m, t=1;
        while(d!=0){
            d=d>>1;
            m=m>>1;
            t++;
        }
        
        while(--t!=0){
            m=m<<1;
        }
        
        return m;
    }
};


/*
// Runtime: 56 ms
// Your runtime beats 6.76 % of cpp submissions. 
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // any diff digits should be 0
        int d=n^m, t=d;
        while(d!=0){
            d=d>>1;
            m=m>>1;
        }
        
        while(0<t){
            t=t>>1;
            m=m<<1;
        }
        
        return m;
    }
};
*/
