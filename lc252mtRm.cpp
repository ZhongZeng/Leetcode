
/*
Leetcode 252. Meeting Rooms

Companies 
Facebook
Related Topics 
Sort
Similar Questions 
Merge Intervals, Meeting Rooms II

Next challenges: Meeting Rooms II

Test Cases:
[]
[[1,2],[2,3],[5,6]]

Runtime: 12 ms
Your runtime beats 35.13 % of cpp submissions.

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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), lessThan);
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start<intervals[i-1].end)   return false;
        }
        return true;
    }
    
    static bool lessThan(Interval& v1, Interval& v2){
        return v1.start<v2.start;
    }
};