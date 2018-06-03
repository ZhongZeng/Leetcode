
/*
Leetcode 845. Longest Mountain in Array

Test Cases:
[2,1,4,7,3,2,5]
[2,2,2]
[0,1,2,3,4,5,4,3,2,1,0]
[0,1,2,3,4,5,6,7,8,9]
[2,3,3,2,0,2]

Runtime: 24 ms

*/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        // O(n) time, O(1) space; tag: array 
        if(A.size()<3)  return false;
        int i, mx=0, mt=0, b=0;// b:0-non,1-ascending,2-descending
        
        for( i=1; i<A.size(); i++ ){
            if(b<1){
                if(A[i-1]<A[i]){
                    b=1;
                    mt=2;
                }
            }else if(b<2){// ascending 
                if(A[i-1]<A[i]){
                    mt++;
                }else if(A[i]<A[i-1]){
                    mt++;
                    b=2;
                }else{
                    mt=1;
                    b=0;
                }
            }else{// descending  
                if(A[i-1]<A[i]){
                    mx=mx<mt?mt:mx;
                    mt=2;
                    b=1;
                }else if(A[i]<A[i-1]){
                    mt++;
                    mx=mx<mt?mt:mx;
                }else{
                    mx=mx<mt?mt:mx;
                    mt=1;
                    b=0;
                }                
            }
            //cout<<mt<<" ";
        }
        //cout<<endl;
        
        if(b==2)    mx=mx<mt?mt:mx;
        return mx<3?0:mx;
    }
};