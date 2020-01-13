/*
1318. Minimum Flips to Make a OR b Equal to c

Company	Microsoft
Related Topics	Bit Manipulation

Test Cases:
2
6
5
4
2
7
1
2
3

Runtime: 0 ms	Your runtime beats 100.00 % of cpp submissions.
Memory Usage: 8.3 MB
*/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        // O(log(a)+log(b)+log(c)) time, O(1) space 
        int ct=0;
        for( ; 0<a||0<b||0<c; a=a>>1, b=b>>1, c=c>>1){
            if(c%2==1)  ct+=a%2==0&&b%2==0;
            else    ct+=(a%2==1)+(b%2==1);
        }
        return ct;
    }
};