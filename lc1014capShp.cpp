/*
1014. Capacity To Ship Packages Within D Days

Companies	Google
Related Topics	Array, Binary Search 

Test Cases:
[1,2,3,4,5,6,7,8,9,10]
5
[3,2,2,4,1,4]
3
[1,2,3,1,1]
4

Runtime: 52 ms
Memory Usage: 11.8 MB

*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        // binary search, O(n*log(500*n)) time, O(1) time;  weights[i] in [1,500] 
        int b=1, e=500*weights.size(), m, db=days(weights,b), de=days(weights,e), dm;// de<=db
        
        while(1<e-b){// D in [de,db), b<e, terminate @ b+1==e
            m=b+(e-b)/2;
            dm=days(weights,m);
            if(D<dm){
                b=m;
                db=dm;
            }else{
                e=m;
                de=dm;
            }
        }
        
        return e;
    }
    
protected:
    int days(vector<int>& weights, int cap){
        int sum=1, t=0;
        for( int i=0; i<weights.size(); i++){
            if(t+weights[i]<=cap){
                t+=weights[i];
            }else{
                if(weights[i]<=cap){
                    sum++;
                    t=weights[i];
                }else{// impossible to fill 
                    return weights.size()+1;
                }
            }
        }
        return sum;
    }
};