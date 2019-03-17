/*
1015. Numbers With Repeated Digits

Companies	Google
Related Topics	Math, Dynamic Programming

Test Cases:
11
20
100
354
3965

Runtime: 4 ms
Memory Usage: 8.1 MB

Next challenges: Scramble String, New 21 Game, Find the Shortest Superstring

https://leetcode.com/problems/numbers-with-repeated-digits/discuss/257123/Count-Number-with-Non-repetitive-Digits-O(9*log(n))-Time-4-ms-32-line
*/

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        // O(9*log(N)) time; N in [1,10^9]; count # no repeated digits <= N; interviewed by Zoom; ex. 7349
        if(N<10)    return 0;
        int sum=0, dg=0, ten=1, i, j, m;
        vector<int> vt(10,0);
        ++N;// if N non-repetive digits: ex. 132, 20
        
        // count # digits of N 
        for( m=N; 0<m; m=m/10, ten*=10, dg++){}
        ten=ten/10;
        
        // # non-repetive i-dight: 9, 90, 738, 5274, 32490, 168570, 712890, 2345850 
        for( i=1; i<dg; i++)    sum+=9*perm(9,i-1);// no prevailing 0 
        
        for( m=N, i=1; 0<m; i++, m=m%ten, ten=ten/10){// ex. (1-6)xxx, 7(0-3)xx 
            int d=m/ten, t=perm(10-i,dg-i);
            
            // ex. 72xx, 71xx, 70xx; no prevailing 0 for 1st digit 
            for( j=i!=1?0:1; j<d; j++)   sum+=vt[j]==0?t:0;
            if(vt[d]==1)    break;
            else    vt[d]=1;
        }
        
        return --N-sum;
    }
    
protected:
    int perm( int b, int len){// =b*(b-1)*...*(b-len+1) 
        int t=1;
        for( int i=0; i<len; i++)   t*=b-i;
        return t;
    }
};