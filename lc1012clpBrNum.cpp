/*
1012. Complement of Base 10 Integer

Companies	Cloudera
Related Topics	Math

Ranking of Weekly Contest 128  
Rank		Name		Score	Finish Time Q1 (2)	Q2 (4)	Q3 (6)	Q4 (8)
353 / 3914	zhongzeng 	12		0:36:48	 	0:06:34	0:14:41 0:31:48	

Test Cases:
5
7
10

Runtime: 4 ms
Memory Usage: 8.2 MB

*/

class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)    return 1;
        int sum=0, t, i;
        
        for( i=1; 0<N; i=i<<1 ){
            t=N-((N>>1)<<1);
            if(t==0)    sum+=i;
            N=N>>1;
        }
        
        return sum;
    }
};