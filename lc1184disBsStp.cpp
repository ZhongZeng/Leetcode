/*
1184. Distance Between Bus Stops

Companies	Google
Related Topics	Array 

Runtime: 4 ms	Your runtime beats 95.83 % of cpp submissions.
Memory Usage: 9.1 MB
*/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        // O(n) time, O(1) space 
        int dis1=0, dis2=0;
        for( int i=start; i!=destination; i=i+1<distance.size()?i+1:0){
            dis1+=distance[i];
        }
        
        destination=0<destination?destination-1:distance.size()-1;
        for( int i=0<start?start-1:distance.size()-1; i!=destination; i=0<i?i-1:distance.size()-1){
            dis2+=distance[i];
        }
        
        return dis1<dis2?dis1:dis2;
    }
};