/*
1094. Car Pooling

Test Cases:
[[2,1,5],[3,3,7]]
4
[[2,1,5],[3,3,7]]
5
[[2,1,5],[3,5,7]]
3
[[3,2,7],[3,7,9],[8,3,9]]
11

Runtime: 12 ms
Memory Usage: 10.2 MB

*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // O(1000+n) time; 0 <= trips[i][1] < trips[i][2] <= 1000
        int cp=0;
        unordered_map<int,int> tp;
        
        for( int i=0; i<trips.size(); i++){// record load&unload
            unordered_map<int,int>::iterator tpi=tp.find(trips[i][1]);
            if(tpi!=tp.end())   tpi->second+=trips[i][0];
            else    tp.emplace(trips[i][1], trips[i][0]);
            tpi=tp.find(trips[i][2]);
            if(tpi!=tp.end())   tpi->second-=trips[i][0];
            else    tp.emplace(trips[i][2],-trips[i][0]);
        }
        
        for( int i=0; i<1001; i++){
            unordered_map<int,int>::iterator tpi=tp.find(i);
            if(tpi!=tp.end()){
                cp+=tpi->second;
                if(capacity<cp) return false;
            }
        }
        
        return true;
    }
};