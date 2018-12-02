
/*
322. Coin Change

Related Topics: Dynamic Programming 

Test Case:
[1,2,5]
11

Runtime: 20 ms, faster than 81.54% of C++ online submissions for Coin Change.

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // DP, O(m*n) time 
        vector<int> vc(amount+1,0);
        vc[0]=1;
        
        for( int i=0, t; i<coins.size(); i++){
            for( int j=1; j<vc.size(); j++){
                t=j-coins[i];
                if(-1<t&&vc[t]!=0){
                    if(vc[j]==0)    vc[j]=vc[t]+1;
                    else    vc[j]=vc[j]<vc[t]+1?vc[j]:vc[t]+1;
                }
            }
        }
        
        return vc.back()-1;// reduce by 1 b/c vc[0]=1
    }
};

// Runtime: 176 ms
// Your runtime beats 7.35 % of cpp submissions.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Knapsack problem, O(m*amount) time 
		int t, mn;
		bool b;
		unordered_map<int,int> um;
		unordered_map<int,int>::iterator umi;
		um.emplace(0,0);
		
		for( int i=1; i<=amount; i++){
			b=false;
			for( int j=0; j<coins.size(); j++){
				t=i-coins[j];
				umi=um.find(t);
				if(umi!=um.end()){
					if(b){
						mn=mn<umi->second+1?mn:umi->second+1;
					}else{
						b=true;
						mn=umi->second+1;
					}
				}
			}
			if(b)um.emplace(i, mn);
		}
		
		umi=um.find(amount);
		
		return umi!=um.end()?umi->second:-1;
    }
};
