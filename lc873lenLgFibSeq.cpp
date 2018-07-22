
/*
Leetcode 873. Length of Longest Fibonacci Subsequence

Weekly Contest 94:166 / 4541 @Jul 21, 2018

Test Cases:
[1,2,3,4,5,6,7,8]
[1,3,7,11,12,14,18]

Runtime: 132 ms

*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        // backtrack + binary search 
        int mx=0;
        
        for( int i=0; i<A.size()-2; i++){
            for( int j=i+1; j<A.size()-1; j++){
                backTrack( i, j, A, mx);
            }
        }
        
        return mx;
    }
    
    void backTrack( int i, int j, vector<int>& A, int& mx){
        int len=2, t;
        
        while( j+1<A.size() ){
            //cout<<A[i]+A[j]<<" ";
            t=binarySearch( j+1, A[i]+A[j], A);
            if(t==-1)   break ;
            i=j;
            j=t;
            len++;
        }
        
        if(len!=2)  mx=mx<len?len:mx;
        
        return ;
    }
    
    int binarySearch( int k, int target, vector<int>& A){// [k, A.size())
        int b=k, e=A.size(), mid;
        
        while(b<e-1){
            mid=b+(e-b)/2;
            if(target<A[mid])   e=mid;
            else    b=mid;
        }
        
        return A[b]!=target?-1:b;
    }
};
