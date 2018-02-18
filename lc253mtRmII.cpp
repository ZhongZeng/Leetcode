
/*
Leetcode 253. Meeting Rooms II

Companies 
Google, Facebook, Snapchat
Related Topics 
Heap, Sort, Greedy
Similar Questions 
Merge Intervals, Meeting Rooms, Minimum Number of Arrows to Burst Balloons

Test Cases:
[[1,4],[4,8]]
[[0, 30],[5, 10],[15, 20]]
[[1,4],[2,5],[6,8],[3,7]]
[[300,5870],[518,2918],[848,3846],[1293,2986],[4284,5907],[4466,4781]]

Runtime: 18 ms
Your runtime beats 16.68 % of cpp submissions. 

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
    int minMeetingRooms(vector<Interval>& intervals) {
        // sort, heap, greedy (use the earliest available room); O(n*lg(n)) time
        if(intervals.size()<1)  return 0;
        sort(intervals.begin(), intervals.end(), lessThan);
        
        int mn=intervals.size();
        bool p;
        vector<Interval> hp={intervals[0]};
        for(int i=1; i<intervals.size(); i++){
            p=false;
            if(hp[0].end<=intervals[i].start){
                p=true; 
                hpPop(hp);
            }
            if(p)   mn--;
            hpPush(hp, intervals[i]);
        }
        
        return mn;
    }
    
protected:    
    static bool lessThan(Interval& v1, Interval& v2){
        return v1.start<v2.start;
    }
    
    void hpPop(vector<Interval>& hp){// heap: smallest end
        int s=0;
        Interval t;
        hp[0]=hp.back();
        hp.pop_back();
        while(s*2+2<hp.size()){
            if(hp[2*s+1].end<hp[s].end&&hp[2*s+1].end<hp[2*s+2].end){
                t=hp[s];
                hp[s]=hp[2*s+1];
                hp[2*s+1]=t;
                s=2*s+1;
            }else if(hp[2*s+2].end<hp[s].end){
                t=hp[s];
                hp[s]=hp[2*s+2];
                hp[2*s+2]=t;
                s=2*s+2;                
            }else{
                return ;
            }
        }
        if(s*2+1<hp.size()&&hp[2*s+1].end<hp[s].end){
            t=hp[s];
            hp[s]=hp[2*s+1];
            hp[2*s+1]=t;            
        }
        return ;
    }
    
    void hpPush(vector<Interval>& hp, Interval& tv){
        int s=hp.size();
        Interval t;
        hp.push_back(tv);
        while(0<s&&hp[s].end<hp[(s-1)/2].end){
            t=hp[(s-1)/2];
            hp[(s-1)/2]=hp[s];
            hp[s]=t;
            s=(s-1)/2;
        }
        return ;
    }
};
