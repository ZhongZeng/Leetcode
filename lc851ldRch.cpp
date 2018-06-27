
/*
Leetcode 851. Loud and Rich

Companies 
Amazon
Related Topics 
Depth-first Search 

Test Case:
[[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
[3,2,5,4,6,1,7,0]

Next challenges: Matchsticks to Square, Freedom Trail, Redundant Connection II

Runtime: 92 ms

*/

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // DFS, greedy, array 
        // quiet is permutation of [0,N) 
        unordered_map<int,unordered_set<int>> rc;
        unordered_map<int,unordered_set<int>>::iterator rci;
        vector<int> rt(quiet.size(),-1), qt(quiet.size(),-1);
        
        for( int i=0; i<quiet.size(); i++)  qt[quiet[i]]=i;// record position in quiet 
        
        for( int i=0; i<richer.size(); i++){// record richer relationship 
            rci=rc.find(richer[i][0]);
            if(rci!=rc.end()){
                rci->second.emplace(richer[i][1]);// richer[i]'s are all different.
            }else{
                unordered_set<int> us;
                us.emplace(richer[i][1]);
                rc.emplace(richer[i][0],us);
            }
        }
        
        for( int i=0; i<qt.size(); i++) dfs( qt[i], qt[i], rt, rc);// dfs
        
        return rt;
    }
    
    void dfs(int& j, int k, vector<int>& rt, unordered_map<int,unordered_set<int>>& rc){
        //cout<<j<<","<<k<<"; ";
        if(-1<rt[k])    return ;// visited 
        rt[k]=j;
        
        unordered_map<int,unordered_set<int>>::iterator rci=rc.find(k);
        if(rci!=rc.end()){
            for( unordered_set<int>::iterator usi=rci->second.begin(); usi!=rci->second.end(); usi++ )
                dfs( j, *usi, rt, rc);
        }
        
        return ;
    }
};

