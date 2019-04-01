/*
1013. Partition Array Into Three Parts With Equal Sum

Ranking of Weekly Contest 129	139 / 4456

Test Cases:
[0,2,1,-6,6,-7,9,1,2,0,1]
[0,2,1,-6,6,7,9,-1,2,0,1]
[3,3,6,5,-2,2,5,1,-9,4]

Runtime: 68 ms
Memory Usage: 12.7 MB

*/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        // greedy, array; zeroing doesn't matter
        int t=0, c=0, tp, i;
        for( i=0; i<A.size(); i++)  t+=A[i];
        if(t%3!=0)  return false;
        else    t=t/3;
        
        for( i=0, tp=0; i<A.size(); i++){
            tp+=A[i];
            if(tp==t){
                tp=0;
                c++;
            }
        }
        
        return tp==0&&c==3;
    }
};