/*
1583. Count Unhappy Friends
Medium
Companies	Bloomberg
Related Topics	Array

Test Cases:
4
[[1,3,2],[2,3,0],[1,0,3],[1,0,2]]
[[2,1],[3,0]]
4
[[1,2,3],[3,2,0],[3,1,0],[1,2,0]]
[[0,1],[2,3]]
2
[[1],[0]]
[[1,0]]
4
[[1,3,2],[2,3,0],[1,3,0],[0,2,1]]
[[1,3],[0,2]]

Runtime: 400 ms	Your runtime beats 18.47 % of cpp submissions.
Memory Usage: 71 MB
*/

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        // O(n*n) time; pairs.length == n/2, preferences.size()==n, preferences[i].size()==n-1 
        vector<unordered_map<int,int>> pref;
        unordered_set<int> unhappy_persons;
        
        for( int i=0; i<preferences.size(); i++){
            unordered_map<int,int> um;
            for( int j=0; j<preferences[i].size(); j++){
                um[preferences[i][j]]=j;
            }
            pref.push_back(um);
        }
        
        for( int i=0; i<pairs.size(); i++){
            for( int j=i+1; j<pairs.size(); j++){
                int x=pairs[i][0], y=pairs[i][1], u=pairs[j][0], v=pairs[j][1];
                areXandUHappy( x, y, u, v, pref, unhappy_persons);
                areXandUHappy( x, y, v, u, pref, unhappy_persons);
                areXandUHappy( y, x, u, v, pref, unhappy_persons);
                areXandUHappy( y, x, v, u, pref, unhappy_persons);
            }
        }
        
        return unhappy_persons.size();
    }
    
protected:
    void areXandUHappy( int x, int y, int u, int v, 
            vector<unordered_map<int,int>> & pref, unordered_set<int> & unhappy_persons){
        if(pref[x][y]>pref[x][u]&&pref[u][v]>pref[u][x]){
            unhappy_persons.emplace(x);
            unhappy_persons.emplace(u);
        }
        return ;
    }
};