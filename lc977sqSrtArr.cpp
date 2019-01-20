/*
977. Squares of a Sorted Array

Related Topics: Array, Two Pointers, Sort 

Test Cases:
[-4,-1,0,3,10]
[-7,-3,2,3,11]

Runtime: 104 ms
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // array, 2-pointer, O(n) time 
		// seen from Google JJ on forum 
        // We find the element with smallest squared value. Then, we start from this element and move towards both ends. We use a two-pointer approach and push the element with smaller squared value into the result and move the pointer pointing to that element. 
        vector<int> rt;
        if(A.size()<1)  return rt;
        int b=0, e, mn=A[0]*A[0];
        
        for( int i=0; i<A.size(); i++){// find smallest A[b]*A[b]
            if(A[i]*A[i]<mn){
                b=i;
                mn=A[i]*A[i];
            }
        }
        e=b+1;
        
        while(-1<b||e<A.size()){
            if(b!=-1&&(e==A.size()||A[b]*A[b]<A[e]*A[e]))   rt.push_back(A[b]*A[b--]);
            else    rt.push_back(A[e]*A[e++]);
        }
        
        return rt;
    }
};
