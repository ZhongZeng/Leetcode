
/*
Leetcode 518. Coin Change 2

Runtime: 4 ms, faster than 72.93% of C++ online submissions for Coin Change 2.

*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // DP, O(m*n) time; amount in [0,5000], coin in [1,5000]
		// if iterate conis within vc, it would count duplicates 
        vector<int> vc(amount+1,0);
        vc[0]=1;

        for( int j=0; j<coins.size(); j++){
            for( int i=1; i<vc.size(); i++){
                if(-1<i-coins[j])   vc[i]+=vc[i-coins[j]];
            }
        }
        
        return vc.back();
    }
};
