
/*
Leetcode 835. Image Overlap

Companies 
Google
Related Topics 
Array 

Next challenges: Median of Two Sorted Arrays, 
Best Time to Buy and Sell Stock with Transaction Fee, Candy Crush

Runtime: 121 ms

*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        // O(n^4) time
		int r, c, mx=0;
        unordered_map<int,unordered_map<int,int>> um;// shift in row/col, #
		unordered_map<int,unordered_map<int,int>>::iterator umi;
		unordered_map<int,int>::iterator usi;
		
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[i].size(); j++){
				for(int k=0; k<B.size(); k++){
					for(int l=0; l<B[k].size(); l++){
						if(A[i][j]!=0&&B[k][l]!=0){
							r=i-k;
							c=j-l;
							umi=um.find(r);
							if(umi!=um.end()){
								usi=umi->second.find(c);
								if(usi!=umi->second.end())	usi->second+=1;
								else	umi->second.emplace(c,1);
							}else{
								unordered_map<int,int> us;
								us.emplace(c,1);
								um.emplace(r,us);
							}
						}
					}
				}
			}
        }
        
		for( umi=um.begin(); umi!=um.end(); umi++){
			for( usi=umi->second.begin(); usi!=umi->second.end(); usi++){
				if(mx<usi->second)	mx=usi->second;
			}
		}
		
		return mx; 
    }
};
