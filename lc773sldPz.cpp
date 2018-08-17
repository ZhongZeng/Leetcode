
/*
Leetcode 773. Sliding Puzzle

Companies   
Airbnb
Related Topics 
Breadth-first Search 

Test Cases:
[[1,2,3],[4,0,5]]
[[1,2,3],[5,4,0]]
[[4,1,2],[5,0,3]]
[[3,2,4],[1,5,0]]

Next challenges: Word Ladder II, Minimum Height Trees, Bus Routes

Runtime: 4 ms
Your runtime beats 98.54 % of cpp submissions.

*/


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
		// BFS, hash table 
        unordered_map<string,int> um;
		vector<string> vs, vt;
		int step=0;
		string s, tg="123450";
		
		for( int i=0; i<board.size(); i++){
			for( int j=0; j<board[i].size(); j++){
				s.push_back((char)board[i][j]+'0');
			}
		}
		
		for( vs.push_back(s); !vs.empty(); step++){
            vt.clear();
			for( int i=0; i<vs.size(); i++){
				if(vs[i]==tg)	return step;
				else	slide( vs[i], vt, um, step);
			}
            vs=vt;
		}
		
		return -1;
    }

protected:	
	void slide( string& s, vector<string>& vt, unordered_map<string,int>& um, int& step){
		int i;
		
		for( i=0; i<s.size()&&s[i]!='0'; i++){}
		
		switch(i){
			case 0:
				swap( i, 1, s, vt, um, step);
				swap( i, 3, s, vt, um, step);
				break;
			case 1:
				swap( i, 0, s, vt, um, step);
				swap( i, 2, s, vt, um, step);
				swap( i, 4, s, vt, um, step);
				break;
			case 2:
				swap( i, 1, s, vt, um, step);
				swap( i, 5, s, vt, um, step);
				break;
			case 3:
				swap( i, 0, s, vt, um, step);
				swap( i, 4, s, vt, um, step);
				break;
			case 4:
				swap( i, 1, s, vt, um, step);
				swap( i, 3, s, vt, um, step);
				swap( i, 5, s, vt, um, step);
				break;
			case 5:
				swap( i, 2, s, vt, um, step);
				swap( i, 4, s, vt, um, step);
				break;
		}
		
		return ;
	}
	
	void swap( int i, int j, string& s, vector<string>& vt, unordered_map<string,int>& um, int& step){
		char t;
		t=s[i];
		s[i]=s[j];
		s[j]=t;
		
		if(um.find(s)==um.end()){
			vt.push_back(s);
			um.emplace(s, step);
		}
		
		t=s[i];
		s[i]=s[j];
		s[j]=t;
		
		return ;
	}
};