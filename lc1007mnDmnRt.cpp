/*
1007. Minimum Domino Rotations For Equal Row

Related Topics:	Array, Greedy

Test Cases:
[2,1,2,4,2,2]
[5,2,6,2,3,2]
[3,5,1,2,3]
[3,6,3,3,4]

*/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        // O(n) time 
        int a=minSwap(A,B), b=minSwap(B,A);
        
        if(a!=-1){
            if(b!=-1)   return a<b?a:b;
            else    return a;
        }
        
        return b;
    }
    
    int minSwap(vector<int>& A, vector<int>& B){
        int i, tg, sw, rt;
        
        for( i=0, tg=A[0], sw=0; i<A.size(); i++){
            if(A[i]==tg){
                
            }else if(B[i]==tg){
                sw++;
            }else{
                sw=-1;
                break;
            }
        }
        rt=sw;
        
        for( i=0, tg=B[0], sw=0; i<A.size(); i++){
            if(A[i]==tg){
                
            }else if(B[i]==tg){
                sw++;
            }else{
                sw=-1;
                break;
            }
        }
        
        if(rt!=-1){
            if(sw!=-1)  return rt<sw?rt:sw;
            else    return rt;
        }
        
        return sw;
    }
};