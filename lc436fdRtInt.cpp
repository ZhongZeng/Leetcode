

/*

Leetcode 436. Find Right Interval

Related Topics
Binary Search
Similar Questions 
Data Stream as Disjoint Intervals

Next challenges: Data Stream as Disjoint Intervals

Test Cases:
[[1,2]]
[[1,2],[2,3]]
[[3,4], [2,3], [1,2]]
[[1,4], [2,3], [3,4]]

Runtime: 91 ms
Your runtime beats 73.91 % of cpp submissions.

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool lessThan( Interval& it1, Interval& it2){
        return it1.start<it2.start;
    }
    
    vector<int> findRightInterval(vector<Interval>& intervals) {
        // You may assume the interval's end point is always bigger than its start point.
        // You may assume none of these intervals have the same start point.
        // Binary Search; Sort; Hash Table; O(n*lg(n)) time 
        vector<int> rt( intervals.size(), -1);
        
        unordered_map<int, int> um;
        for( int i=0; i<intervals.size(); i++)  um.emplace( intervals[i].start, i);
        
        sort(intervals.begin(), intervals.end(), lessThan);
        //for(auto e:intervals)   cout<<e.start<<","<<e.end<<" "; cout<<endl;
        
        for( int i=0, p; i<intervals.size(); i++){
            rt[um.find(intervals[i].start)->second]=binarySearch( intervals, i, intervals.size(), um);
        }
        
        return rt;
    }
    
    // previously I put lessThan here, and it doesn't compile 
    
    int binarySearch(vector<Interval>& intervals, int b , int e, unordered_map<int, int>& um){
        int mid, tg=intervals[b].end;
        
        while(b<e-1){//[b,e)
            mid=b+((e-b)>>1);
            if(intervals[mid].start<tg) b=mid;
            else    e=mid;
        }
        
        return e!=intervals.size()&&tg<=intervals[e].start?um.find(intervals[e].start)->second:-1;
    }
};
