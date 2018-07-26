
/*
Leetcode 386. Lexicographical Numbers

Companies  
Amazon 4, Bloomberg 

Test Case:
13

Runtime: 272 ms
Your runtime beats 6.45 % of cpp submissions.

Runtime: 268 ms
Your runtime beats 7.69 % of cpp submissions.

Next challenges: Binary Tree Maximum Path Sum, Design Circular Queue, Score After Flipping Matrix
Next challenges: Binary Tree Maximum Path Sum, Find Duplicate Subtrees, Bold Words in String

*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> rt;
		if(n<1)	return rt;
		
		for( int i=1; i<10; i++)    dfs( i, n, rt);
		
		return rt;
    }
	
	void dfs( int i, int& n, vector<int> & rt){// DFS, backtrack
		if(n<i)	return ;
		else	rt.push_back(i);
		
		for( int j=0; j<10; j++){
			dfs( i*10+j, n, rt);
		}
		
		return ;
	}
};
