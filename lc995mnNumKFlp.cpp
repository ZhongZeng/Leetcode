/*
995. Minimum Number of K Consecutive Bit Flips

Related Topics: Array, suggested: Greedy, Queue 

Test Cases:
[0,1]
2
[0,1,0]
1
[1,1,0]
2
[0,0,0,1,0,1,1,0]
3

Runtime: 92 ms
Memory Usage: 17.5 MB

We traverse the array from begining to end. We flip to make every acutal zero to one. 
*/

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {// greedy, O(n) time, O(k) space
        int sum=0;
        queue<int> qu;// flips until
        
        for( int i=0; i<=A.size()-K; i++){
            if(!qu.empty()&&qu.front()<i)    qu.pop();
            
            if((A[i]+qu.size())%2==0){// A[i]'s value a/t flips
                sum++;
                qu.push(i+K-1);
            }
        }
        
        for( int i=A.size()-K+1; i<A.size(); i++){
            if(!qu.empty()&&qu.front()<i)    qu.pop();
            if((A[i]+qu.size())%2==0)   return -1;
        }
        
        return sum;
    }
};