
/*
Leetcode 435. Non-overlapping Intervals

Related Topics 
Greedy 
Similar Questions 
Minimum Number of Arrows to Burst Balloons 

Test Cases:
[ [1,2], [2,3], [3,4], [1,3] ]
[ [1,2], [1,2], [1,2] ]
[ [1,2], [2,3] ]
[[1,100],[11,22],[1,11],[2,12]]

Runtime: 9 ms
Your runtime beats 23.68 % of cpp submissions.

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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        // sort; classic greedy problem 
        // O(nlg(n)) time 
        if(intervals.size()<2)   return 0;
        int num=0, ed;
        mergeSort(intervals, 0, intervals.size());
        //for(auto ele : intervals)    cout<<ele.start<<","<<ele.end<<" ";
        
        ed=intervals[0].end;
        for(int i=1; i!=intervals.size(); i++){
            if(intervals[i].start<ed){
                num++;
            }else{
                ed=intervals[i].end;
            }
        }
        return num;
    }
    
    void mergeSort(vector<Interval>& intervals, int s, int e){
        // [s,e)
        //cout<<s<<"-"<<e<<endl;
        if(e-s<2){
            return;
        }else if(2<e-s){
            int mid=s+(e-s)/2;
            mergeSort(intervals, s, mid);
            mergeSort(intervals, mid, e);
            merge(intervals, s, mid, e);            
        }else if(intervals[s+1].end<intervals[s].end){
            Interval itv;
            itv=intervals[s];
            intervals[s]=intervals[s+1];
            intervals[s+1]=itv;
        }
        return ;
    }
    
    void merge(vector<Interval>& intervals, int s, int mid, int e){
        // [s,mid), [mid,e)
        vector<Interval> vc;
        for(int i=s; i!=mid; i++)   vc.push_back(intervals[i]);
        for(int i=s, j=0, k=mid; j!=mid-s; i++){
            if(vc[j].end<intervals[k].end||k==e){
                intervals[i]=vc[j];
                j++;
            }else{
                intervals[i]=intervals[k];
                k++;                
            }
        }
        return ;
    }
    
};
