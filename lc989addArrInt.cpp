
/*
989. Add to Array-Form of Integer

Ranking of Weekly Contest 123 
708 / 3468

Related Topics: Array 

Test Cases:
[1,2,0,0]
34
[9,9,9,9,9,9,9,9,9,9]
1
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        // O(n) time, O(1) space, modify in-place
        reverse(A.begin(),A.end());
        
        int a=0;
        for( int i=0; i<A.size(); K/=10, i++){
            A[i]+=K%10+a;
            if(9<A[i]){
                a=1;
                A[i]-=10;
            }else{
                a=0;
            }
        }
        for( ; a!=0||K!=0; K/=10){
            A.push_back(K%10+a);
            if(9<A.back()){
                a=1;
                A.back()-=10;
            }else{
                a=0;
            }
        }
        
        reverse(A.begin(),A.end());
        return A;
    }
};