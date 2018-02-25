
/*
789. Escape The Ghosts

Weekly Contest 73  

Test Cases:
[[1,0],[0,3]]
[0,1]
[[1, 0]]
[2,0]
[[2, 0]]
[1,0]

Runtime: 5 ms

*/

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        // possible to escape
        // for any given moves the ghosts may take
        int mv=abs(target[0])+abs(target[1]), gh;
        for(int i=0; i<ghosts.size(); i++){
            gh=abs(ghosts[i][0]-target[0])+abs(ghosts[i][1]-target[1]);
            if(gh<=mv)  return false;// ghost@target first
        }
        return true;
    }
    
    int abs(int i){
        return i<0?0-i:i;
    }
};