
/*
Leetcode 499. The Maze III

Companies   
Google 3
Related Topics 
Depth-first Search 
Similar Questions 
The Maze, The Maze II

Test Cases:
[[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]]
[4,3]
[0,1]
[[0,0,0,0,0,0,0],[0,0,1,0,0,1,0],[0,0,0,0,1,0,0],[0,0,0,0,0,0,1]]
[0,4]
[3,5]

Runtime: 4 ms
Your runtime beats 100.00 % of cpp submissions.

Next challenges: Trapping Rain Water II, Freedom Trail, Number of Distinct Islands

*/

#include<priority_queue>
#include<vector> 
#include<iostream>
using namespace std; 

struct Pt{
    int dis, x, y;
    string dr;// last direction to this element 
    Pt( int a, int b, int c, string d):dis(a),x(b),y(c),dr(d){}
};

bool greaterThan(Pt& pt1, Pt& pt2){// min heap 
    if(pt1.dis>pt2.dis){
        return true;
    }else if(pt1.dis<pt2.dis){
        return false;
    }else{
        for( int i=0; i<pt1.dr.size()&&i<pt2.dr.size(); i++){
            if(pt1.dr[i]>pt2.dr[i]) return true;
            else if(pt1.dr[i]<pt2.dr[i])    return false;
        }
        return pt1.dr.size()>pt2.dr.size();// lexicographically smallest 
    }    
}

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        // maze.size()<=30&&maze[0].size()<=30 
        // think hole as a place where ball can stop 
        // Dijkstra, BFS, greedy: O(m*n) space, O(m*n*log(m*n)) time 
        string rt;
        int dis, x, y, i, j;
        
        priority_queue<Pt, vector<Pt>, decltype(&greaterThan)> pq(&greaterThan);// let me try priority queue STL once 
        pq.emplace(0,ball[0],ball[1],"");// xl,yl,dr don't matter 
        
        while(!pq.empty()){
            Pt pt1=pq.top();
            pq.pop();// pop top 
            x=pt1.x;
            y=pt1.y;
            
            if(maze[x][y]==0){// unvisited 
                maze[x][y]=-1;
                dis=pt1.dis;
                string s=pt1.dr;
                //cout<<x<<","<<y<<":"<<dis<<":"<<pt1.dr<<" ";
                
                if(x==hole[0]&&y==hole[1])  return s;
                
                for( i=x; i+1<maze.size()&&maze[i+1][y]!=1; i++)    if(i==hole[0]&&y==hole[1])  break;
                if(maze[i][y]==0){
                    s.push_back('d');
                    pq.emplace(dis+i-x,i,y,s);
                    s.pop_back();
                }
                
                for( i=x; 0<i&&maze[i-1][y]!=1; i--)    if(i==hole[0]&&y==hole[1])  break;
                if(maze[i][y]==0){
                    s.push_back('u');
                    pq.emplace(dis+x-i,i,y,s);
                    s.pop_back();
                }
                
                for( j=y; j+1<maze[0].size()&&maze[x][j+1]!=1; j++) if(x==hole[0]&&j==hole[1])  break;
                if(maze[x][j]==0){
                    s.push_back('r');
                    pq.emplace(dis+j-y,x,j,s);
                    s.pop_back();
                }
                
                for( j=y; 0<j&&maze[x][j-1]!=1; j--)    if(x==hole[0]&&j==hole[1])  break;
                if(maze[x][j]==0){
                    s.push_back('l');
                    pq.emplace(dis+y-j,x,j,s);
                    s.pop_back();
                }
            }
        }
        
        return "impossible";
    }
};

int main(){
	
	
	return 0; 
}