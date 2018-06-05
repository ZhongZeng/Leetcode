
/*
Leetcode 77. Combinations

Related Topics 
Backtracking
Similar Questions 
Combination Sum, Permutations

Next challenges: Combination Sum

Test Cases:
4
2
5
3

Your runtime beats 34.73 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		// similar to combination, but just first k elements; DFS 
		vector<vector<int>> rt;
        vector<int> vc, v;
		for( int i=1; i<=n; i++)	vc.push_back(i);
		
		backtrack( 0, k, v, vc, rt);
		
		return rt;
    }
	
	void backtrack( int i, int k, vector<int>& v, vector<int>& vc, vector<vector<int>>& rt){
		
        if(k!=0){
            for( int j=i; j<=vc.size()-k; j++){
                v.push_back(vc[j]);
                
                backtrack( j+1, k-1, v, vc, rt);

                v.pop_back();
            }            
        }else{
            rt.push_back(v);
        }
		
		return ;
	}
};
