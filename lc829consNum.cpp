

/*
Leetcode 829. Consecutive Numbers Sum

Test Cases: 
5
9
15
45
200
201
933320757

Runtime: 13 ms

*/

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        // math: N=sum( i+1, i+2, ... , i+k)=(2*i+k+1)*k/2 => i=N/k-(k+1)/2>0
        // k < (-1+sqrt(1+8*N))/2
        // O(n) time is trivial 
        int sum=0, l=(-1+sqrt(1+(long)8*N))/2+1; //(-1+sqrt(1+8*N))/2
        
        for(int k=1; k<l; k++){
            if(N/k-(k+1)/2==N*1.0/k-(k+1)/2.0){
                //cout<<" true:"<<k<<","<<(N/k-(k+1)/2);
                sum++;
            }
        }
        
        return sum;
    }
};
