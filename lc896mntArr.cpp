

/*
Leetcode 896. Monotonic Array

Related Topics 
Array 

Test Cases:
[1,2,2,3]
[6,5,4,4]
[1,3,2]
[1,2,4,5]
[1,1,1]

Runtime: 104 ms

*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int i=0;
        bool b=true;
        
        while( ++i<A.size() ){
            if(A[i]<A[i-1]){
                b=false;
                break;
            }else if(A[i-1]<A[i]){
                break;
            }
        }
        
        if(b){
            for( ; i<A.size(); i++){
                if(A[i]<A[i-1]) return false;
            }
        }else{
            for( ; i<A.size(); i++){
                if(A[i-1]<A[i]) return false;
            }            
        }
        
        return true;
    }
};
