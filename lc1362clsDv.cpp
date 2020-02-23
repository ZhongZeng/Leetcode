/*
1362. Closest Divisors

Company	Amazon
Related Topics	Math

Test Cases:
8
123
999

Runtime: 12 ms
Memory Usage: 8.3 MB
*/

class Solution {
public:
    vector<int> closestDivisors(int num) {
        // num in [1, 10**9]
        vector<int> vc1=closestDivisors0(num+1), vc2=closestDivisors0(num+2);
        return vc1[1]-vc1[0]<vc2[1]-vc2[0]?vc1:vc2;
    }
    
protected:
    vector<int> closestDivisors0(int num){
        int sq_root=sqrt(num)+1;
        vector<int> vc={1, num};
        for( int i=1; i<sq_root; i++){
            if(num%i==0){// compare num%i with 0 & 1 is faster linearly
                vc[0]=i;
                vc[1]=num/i;
            }
        }
        return vc;
    }
};