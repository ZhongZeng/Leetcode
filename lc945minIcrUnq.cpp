

/*
945. Minimum Increment to Make Array Unique

suggest tag: vector, greedy 

My Linkedin OA

Test Case:
[1,2,2]
[3,2,1,2,1,7]
[0,1,3,3]
[7,2,7,2,1,4,3,1,4,8]

Runtime: 64 ms

*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        // O(n*log(n)) time
        if(A.size()<2)  return 0;
        int rt=0, b, e, t;
        sort(A.begin(), A.end());
        
        for( b=1, e=0; b<A.size(); b++){
            if(A[b]==A[b-1]){
                findNextGap( A, b, e, t);
                rt+=t-A[b];
            }
        }
        
        return rt;
    }
    
    void findNextGap(vector<int>& A, int& b, int& e, int& t){
        if(e<=b){
            e=b+1;
            t=A[b];
        }    
        
        if(e<A.size()&&A[e]<=t+1){
            while( ++e<A.size() ){
                if(A[e-1]+1<A[e])   break;
            }
            t=A[e-1]+1;
        }else{// e>=A.size()||A[e]>t+1
            t++;
        }
        
        return ;
    }
};