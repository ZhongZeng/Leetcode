/*
Leetcode 286. Walls and Gates

Companies	Google, Facebook
Related Topics	Breadth-first Search
Similar Questions	Surrounded Regions, Number of Islands, Shortest Distance from All Buildings

Next challenges: Shortest Distance from All Buildings

Test Cases:
[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
[[2147483647,0,2147483647,2147483647,0,2147483647,-1,2147483647]]
[[],[]]
[[]]
*/

// Runtime: 116 ms, faster than 24.56% of C++ online submissions for Walls and Gates.
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
		// BFS from all gates, O(m*n) time )
        vector<int> vc, vd;
		for( int i=0; i<rooms.size(); i++){
			for( int j=0; j<rooms[i].size(); j++){
				if(rooms[i][j]==0){
					vc.push_back(i);
					vc.push_back(j);
				}
			}
		}
		
		for( int d=1; !vc.empty(); d++){
			vd.clear();
			for( int k=0, i, j; k<vc.size(); k+=2){
				i=vc[k];
				j=vc[k+1];
				if(0<i&&d<rooms[i-1][j]){
					rooms[i-1][j]=d;
					vd.push_back(i-1);
					vd.push_back(j);
				}
				if(0<j&&d<rooms[i][j-1]){
					rooms[i][j-1]=d;
					vd.push_back(i);
					vd.push_back(j-1);
				}
				if(i<rooms.size()-1&&d<rooms[i+1][j]){
					rooms[i+1][j]=d;
					vd.push_back(i+1);
					vd.push_back(j);
				}
				if(j<rooms[i].size()-1&&d<rooms[i][j+1]){
					rooms[i][j+1]=d;
					vd.push_back(i);
					vd.push_back(j+1);
				}
			}
			vc=vd;
		}
		
		return ;
    }
};

// Runtime: 112 ms	Your runtime beats 38.62 % of cpp submissions.
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // BFS (thought about where to begin BFS); 0:0; -1:-1; 2147483647
        int x, y;
        vector<pair<int,int>> qu1, qu2;
        for(int i=0; i<rooms.size(); i++){
            for(int j=0; j<rooms[0].size(); j++){
                if(rooms[i][j]==0)  qu1.push_back(make_pair(i,j));
            }
        }
        
        while(!qu1.empty()){
            qu2=nbfsNext(qu1, rooms);
            
            qu1=nbfsNext(qu2, rooms);
        }
        
        return ;
    }
    
protected:    
    vector<pair<int,int>> nbfsNext(vector<pair<int,int>>& qu1, vector<vector<int>>& rooms){
        // non-obstacle element is pushed into vector only once 
        vector<pair<int,int>> qu2;
        int x, y;
        for(int i=0; i<qu1.size(); i++){
            x=qu1[i].first;
            y=qu1[i].second;
            if(0<x&&rooms[x-1][y]!=-1&&rooms[x][y]+1<rooms[x-1][y]){
                rooms[x-1][y]=rooms[x][y]+1;
                qu2.push_back(make_pair(x-1,y));
            }
            if(0<y&&rooms[x][y-1]!=-1&&rooms[x][y]+1<rooms[x][y-1]){
                rooms[x][y-1]=rooms[x][y]+1;
                qu2.push_back(make_pair(x,y-1));
            }
            if(x<rooms.size()-1&&rooms[x+1][y]!=-1&&rooms[x][y]+1<rooms[x+1][y]){
                rooms[x+1][y]=rooms[x][y]+1;
                qu2.push_back(make_pair(x+1,y));
            }
            if(y<rooms[0].size()-1&&rooms[x][y+1]!=-1&&rooms[x][y]+1<rooms[x][y+1]){
                rooms[x][y+1]=rooms[x][y]+1;
                qu2.push_back(make_pair(x,y+1));
            }
        }
        
        return qu2;
    }
};
