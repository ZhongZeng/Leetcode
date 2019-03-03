/*
1004. Max Consecutive Ones III

Related Topics:	Two Pointers 

Test Cases:
[1,1,1,0,0,0,1,1,1,1,0]
2
[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
3

*/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        // 2-pointer, greedy, O(n) time; previously thought about queue; A.size() in [1,20000] 
        // corner case K==0 
        int b=0, e=0, mx=0;// [b,e) 
        
        while( e<A.size()&&0<K ){// longest consecutive '1's from begin() 
            if(A[e]==0) K--;
            e++;
            mx=mx<e-b?e-b:mx;
        }
        
        while( e<A.size() ){// [b,e) 
            if(A[e]==0){
                while(b<e&&A[b]==1) b++;
                b++;
            }
            e++;
            mx=mx<e-b?e-b:mx;
        }
        
        return mx;
    }
};