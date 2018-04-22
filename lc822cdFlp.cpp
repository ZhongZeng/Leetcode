
/*
Leetcode 822. Card Flipping Game

Weekly Contest 81  

Test Cases:
[1,2,4,4,7]
[1,3,4,1,3]
[1,1]
[1,2]

Runtime: 26 ms

*/

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        // O(n) time&space; O(n**2) is trivial
        // 1 <= fronts[i] <= 2000.
        // 1 <= backs[i] <= 2000.
        int rt=2001;
        unordered_set<int> us;// not good number 
        unordered_set<int>::iterator usi;
        for(int i=0; i<fronts.size(); i++){
            if(fronts[i]==backs[i]){
                usi=us.find(fronts[i]);
                if(usi==us.end())   us.emplace(fronts[i]);                
            }
        }
        
        for(int i=0; i<fronts.size(); i++){
            if(us.find(fronts[i])==us.end()&&fronts[i]<rt)  rt=fronts[i];
            if(us.find(backs[i])==us.end()&&backs[i]<rt)    rt=backs[i];
        }
     
        return rt!=2001?rt:0;
    }
};
