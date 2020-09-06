/*
1102. Path With Maximum Minimum Value

Medium
Companies	Amazon
Related Topics	Depth-first Search, Union Find, Graph

Test Cases:
[[5,4,5],[1,2,6],[7,4,6]]
[[2,2,1,2,2,2],[1,2,2,2,1,2]]
[[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]

Runtime: 532 ms, faster than 90.14% of C++ online submissions for Path With Maximum Minimum Value.
Memory Usage: 32.9 MB, less than 53.14% of C++ online submissions for Path With Maximum Minimum Value.
Next challenges: Matchsticks to Square, Sort Integers by The Power Value,
Parallel Courses II
*/

struct cell{
    int x, y, v;
    
    cell( int x_, int y_, int v_){
        x=x_;
        y=y_;
        v=v_;
    }
};

struct compare{
    bool operator ()(cell c1, cell c2){
        return c1.v<c2.v;
    }
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        // BFS+Greedy, Dijkstra; A[i][j] in [0,10**9]
        vector<vector<int>> scores( A.size(), vector<int> (A[0].size(), -1));
        priority_queue<cell, vector<cell>, compare> pq;
		pushToPriorityQueue( 0, 0, A[0][0], A, scores, pq);
        
        while(scores.back().back()==-1){
            cell c=pq.top();
			pq.pop();
			
			if(0<c.x) pushToPriorityQueue(c.x-1, c.y, c.v, A, scores, pq);
            if(0<c.y) pushToPriorityQueue(c.x, c.y-1, c.v, A, scores, pq);
			if(c.x+1<A.size())    pushToPriorityQueue(c.x+1, c.y, c.v, A, scores, pq);
			if(c.y+1<A[c.x].size())	pushToPriorityQueue(c.x, c.y+1, c.v, A, scores, pq);
        }
        
        return scores.back().back();
    }
	
protected:
	void pushToPriorityQueue( int x, int y, int v, vector<vector<int>> & A,
        vector<vector<int>> & scores, priority_queue<cell, vector<cell>, compare> & pq){
        if(scores[x][y]!=-1)    return ;
        int score=A[x][y]<v?A[x][y]:v;
		pq.push(cell(x, y, score));
        scores[x][y]=score;// mark score when pushing is fine b/c score is min value in path
		return ;
	}
};