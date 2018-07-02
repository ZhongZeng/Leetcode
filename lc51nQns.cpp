
/*
Leetcode 51. N-Queens

Related Topics 
Backtracking 
Similar Questions 
N-Queens II

Test Cases:
4
5
9

Next challenges: Word Ladder II, Palindrome Partitioning, Additive Number

Runtime: 4 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		// backtrack+DFS, similiar to Leetcode 52 N-Queens II
		vector<vector<string>> rt;
        vector<int> vc, vs(2*n-1,-1), vd(2*n-1,-1);
		for( int i=0; i<n; i++)	vc.push_back(i);
		
		dfs( 0, vc, vs, vd, rt);
		
		return rt; 
    }
	
	void dfs( int j, vector<int>& vc, vector<int>& vs, vector<int>& vd, vector<vector<string>>& rt){
		if(j==vc.size())	pushQ( vc, rt);
		
		for( int i=j, t; i<vc.size(); i++){
			t=vc[i];
			vc[i]=vc[j];
			vc[j]=t;
			
			if(vs[vc[j]+j]==-1&&vd[vc[j]-j+vc.size()-1]==-1){
				vs[vc[j]+j]=1;
				vd[vc[j]-j+vc.size()-1]=1;
				
				dfs( j+1, vc, vs, vd, rt);

				vs[vc[j]+j]=-1;
				vd[vc[j]-j+vc.size()-1]=-1;
			}
			
			t=vc[i];
			vc[i]=vc[j];
			vc[j]=t;			
		}
		
		return ;
	}
	
	void pushQ( vector<int>& vc, vector<vector<string>>& rt){
		string s(vc.size(),'.');
		vector<string> vs(vc.size(),s);
		
		for( int i=0; i<vc.size(); i++)	vs[i][vc[i]]='Q';
		
		rt.push_back(vs);
		
		return ;
	}
	
};

