/*
1005. Maximize Sum Of Array After K Negations

Ranking of Weekly Contest 127  
Rank		Score	Q1 (4)	Q2 (4)	Q3 (5)	Q4 (6)
674 / 4724	19		0:17:53	0:38:08	0:48:44	1:10:27

Related Topics:	Greedy 

Test Cases:
[4,2,3]
1
[3,-1,0,2]
3
[2,-3,-1,5,-4]
2

*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        // choose K smallest negative #
        priority_queue<int> pq;
        int sum=0;
        
        if(A.size()<1)  return 0;// corner case: empty array
        if(K==0){// conrner case: K==0 
            for( int i=0; i<A.size(); i++)  sum+=A[i];
            return sum;
        }
        
        for( int i=0; i<A.size(); i++){// 1<=K
            sum+=A[i];
            if(A[i]<0){
                if(pq.size()<K){
                    pq.push(A[i]);
                }else if(A[i]<pq.top()){
                    pq.pop();
                    pq.push(A[i]);
                }
            }
        }
        
        while(0<pq.size()){
            sum-=2*pq.top();
            pq.pop();
            K--;
        }
        
        if(K%2==1){
            int mp=A[0]<0?(-A[0]):A[0];
            for( int i=0; i<A.size(); i++){
                if(0<A[i])  mp=A[i]<mp?A[i]:mp;
                else    mp=(-A[i])<mp?(-A[i]):mp;
            }
            sum-=mp*2;
        }
        
        return sum;
    }
};