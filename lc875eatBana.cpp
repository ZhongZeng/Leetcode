
/* 
Leetcode 875. Koko Eating Bananas

Weekly Contest 94:166 / 4541 @Jul 21, 2018

Test Cases: 
[3,6,7,11]
8
[30,11,23,4,20]
5
[30,11,23,4,20]
6

Runtime: 44 ms


*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // binary search, O(n*log(1000000001)) time; piles.size()<=H 
        int b=0, e=1000000001, mid, hr;// (b,e], 10**9+1
        
        while( b<e-1){
            mid=b+(e-b)/2;
            hr=eatAll(mid, piles);
            if(H<hr)    b=mid;
            else    e=mid;
        }
        
        return e;
    }
    
    int eatAll( int& mid, vector<int>& piles ){
        int hr=0;
        
        for( int i=0; i<piles.size(); i++){
            hr+=piles[i]/mid;
            if(piles[i]%mid!=0) hr++;
        }
        
        return hr;
    }
};