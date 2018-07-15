
/*
Leetcode 868. Binary Gap

Test Cases:
22
5
6
8

Runtime: 4 ms

*/

class Solution {
public:
    int binaryGap(int N) {
        int d=0, i=0, ls=-1;
        
        while(N!=0){
            if((N>>1)<<1!=N){// ==1
                if(ls!=-1)  d=d<i-ls?i-ls:d;
                ls=i;
            }
            i++;
            N=N>>1;
        }
        
        return d;
    }
};
