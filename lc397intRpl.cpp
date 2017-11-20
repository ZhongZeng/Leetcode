
/*
Leetcode 397. Integer Replacement

Related Topics 
Math, Bit Manipulation 

Next challenges: Max Points on a Line, Minimum Factorization, 
Find the Derangement of An Array

Test Cases:
4
5
6
7
15
8
11
12
65535
10000
100000000

Runtime: 3 ms
You are here! 
Your runtime beats 18.09 % of cpp submissions.

*/

class Solution {
public:
    int integerReplacement(int n) {
        // think about this as binary format
        // 011, 01: -1; 0111: +1
        int sum=0, r=0;
        while( n!=1 ){
            //cout<<n%2;
            if( n%2!=0 ){
                r++;
            }else{
                if(1<r){
                    sum=sum+1;
                    r=1;
                }else if(r==1){
                    sum++;
                    r=0;
                }
            }
            
            sum++;            
            n=n>>1;
        }
        
        // last digit is different
        if(r==1){
            sum++;
            r=0;
        }else if(r==2){
            sum=sum+2;
            r=0;
        }else if(2<r){
            sum=sum+2;
        }
        
        return sum;
    }
};
