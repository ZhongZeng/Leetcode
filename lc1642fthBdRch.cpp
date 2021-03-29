/*
1642. Furthest Building You Can Reach
Medium

Companies:	Google
Related Topics:	Binary Search, Heap 

Runtime: 76 ms, faster than 98.95% of C++ online submissions for Furthest Building You Can Reach.
Memory Usage: 53.6 MB, less than 49.02% of C++ online submissions for Furthest Building You Can Reach.
Next challenges: Shortest Path to Get All Keys, Nth Magical Number, 
Find the Most Competitive Subsequence
*/

struct comp{
    bool operator()(int a, int b){
        return a>b;
    }
};

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        long total_climbs=0, max_climb_sum=0, i;
        priority_queue<int,vector<int>,comp> max_climbs;
        
        for( i=1; i<heights.size(); i++){
            long this_climb=heights[i]-heights[i-1];
            if(0<this_climb){
                total_climbs+=this_climb;
                if(0<ladders){
                    if(max_climbs.size()<ladders){
                        max_climb_sum+=this_climb;
                        max_climbs.push(this_climb);
                    }else if(max_climbs.top()<this_climb){
                        max_climb_sum+=this_climb-max_climbs.top();
                        max_climbs.pop();
                        max_climbs.push(this_climb);
                    }
                }
                if(bricks<total_climbs-max_climb_sum)
                    return i-1;
            }
        }
        
        return heights.size()-1;
    }
};