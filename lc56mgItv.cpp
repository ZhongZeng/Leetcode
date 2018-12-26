/*
Leetcode 56. Merge Intervals

Related Topics 
Array, Sort
Similar Questions 
Insert IntervalMeeting Rooms, Meeting Rooms II, 
Teemo Attacking, Add Bold Tag in String, Range Module

Test Cases:
[[1,3],[2,6],[8,10],[15,18]]
[[1,3],[2,6],[8,10],[15,18],[18,19],[21,23]]
[[0,2],[2,3],[4,4],[0,1],[5,7],[4,5],[0,0]]
[[1,3],[2,6],[8,10],[15,18]]
[[1,4],[2,3]]

Runtime: 8 ms, faster than 99.25% of C++ online submissions for Merge Intervals.
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
    vector<Interval> merge(vector<Interval>& intervals) {
        // sort; O(n*log(n)) time, O(1) space, modify input 
        int i, j, k;
        
        sort(intervals.begin(),intervals.end(),lessThan);
        
        for( i=0, j=0; j<intervals.size(); i++){
            intervals[i]=intervals[j];
            for( k=j+1; k<intervals.size(); k++){
                if(intervals[i].end<intervals[k].start){
                    break;
                }else{
                    if(intervals[i].end<intervals[k].end)
                        intervals[i].end=intervals[k].end;
                }
            }
            j=k;// j increase at least 1 
        }
        intervals.erase(intervals.begin()+i,intervals.end());
        
        return intervals;
    }
    
    static bool lessThan(Interval& v1, Interval& v2){
        return v1.start<v2.start;
    }
};

// Runtime: 8 ms, faster than 99.25% of C++ online submissions for Merge Intervals. Run now
// Runtime: 22 ms	Your runtime beats 8.48 % of cpp submissions. Run 1 year ago 
// Runtime: 26 ms	Your runtime beats 7.01 % of cpp submissions.
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        // merge sort, greedy, 2-pointer
        if(intervals.size()<1)  return {};
        mergeSort(intervals, 0, intervals.size());
        //for(auto ele:intervals) cout<<ele.start<<"-"<<ele.end<<" ";
        
        int i=0, j=0;
        while(++j!=intervals.size()){
            if(intervals[j].start<=intervals[i].end){
                if(intervals[i].end<intervals[j].end){
                    intervals[i].end=intervals[j].end;
                }
            }else{
                i++;
                intervals[i]=intervals[j];
            }
        }
        
        intervals.erase(intervals.begin()+i+1,intervals.end());
        
        return intervals;
    }
    
    void mergeSort(vector<Interval>& intervals, int bg, int ed){
        if(ed-bg<2) return;
        int mid=bg+(ed-bg)/2;
        mergeSort(intervals, bg, mid);
        mergeSort(intervals, mid, ed);
        merge(intervals, bg, mid, ed);
        return ;
    }
    
    void merge(vector<Interval>& intervals, int bg, int mid, int ed){
        // polymorphism
        vector<Interval> vc;
        for(int i=bg; i!=mid; i++)  vc.push_back(intervals[i]);
        
        for(int i=0, j=mid, k=bg; i!=vc.size(); k++){
            if(vc[i].start<intervals[j].start||j==ed){
                intervals[k]=vc[i];
                i++;
            }else{
                intervals[k]=intervals[j];
                j++;
            }
        }
        
        return ;
    }
    
};