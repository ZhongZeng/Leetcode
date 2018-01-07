

/*
Leetcode 759. Employee Free Time

[[[1,2],[5,6]],[[1,3]],[[4,10]]]
[[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
[[[1,2],[5,6]],[[1,3]],[[4,10]]]
[[[45,56],[89,96]],[[5,21],[57,74]]]
[[[0,1],[12,19]],[[5,10],[90,100]],[[13,21]],[[1,3]]]
[[[30,62],[69,73]],[[86,91],[97,100]],[[30,58],[76,93]],[[56,58],[71,73]]]
[[[0,1],[12,19],[42,54],[78,80],[89,93]],[[5,10],[30,62],[69,73],[80,83],[90,100]],[[13,21],[23,29],[42,43],[86,91],[97,100]],[[0,11],[24,25],[30,58],[76,93],[94,97]],[[1,3],[46,50],[56,58],[71,73],[77,99]]]

Runtime: 66 ms

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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        // Each employee has a list of non-overlapping Intervals, 
        // and these intervals are in sorted order(both in start&end). 
        vector<pair<Interval,vector<int>>> vc;
        vector<Interval> rt;
        int i, j;
        // merge all intervals: heap, greedy
        for(i=0; i<avails.size(); i++)  pushHp(vc, avails[i][0], i, 0);
        //for(auto ele:vc)    cout<<ele.first.start<<","<<ele.first.end<<" "; cout<<endl;
        
        i=vc[0].second[0];
        j=vc[0].second[1];
        rt.push_back(vc[0].first);
        if(j+1<avails[i].size())  rlpHp(vc, avails[i][j+1], i, j+1);
        else    popHp(vc);
        
        while(!vc.empty()){
            i=vc[0].second[0];
            j=vc[0].second[1];
            
            if(rt.back().end<vc[0].first.start)   rt.push_back(vc[0].first);
            else if(rt.back().end<vc[0].first.end)  rt.back().end=vc[0].first.end;
            
            if(j+1<avails[i].size())  rlpHp(vc, avails[i][j+1], i, j+1);
            else    popHp(vc);
            //for(auto ele:vc)    cout<<ele.first.start<<","<<ele.first.end<<" "; cout<<endl;
        }
        //for(auto ele:rt)    cout<<ele.start<<","<<ele.end<<" "; cout<<endl;
        
        // find free time
        for(i=0; i<rt.size()-1; i++){
            rt[i].start=rt[i].end;
            rt[i].end=rt[i+1].start;
        }
        rt.pop_back();
       
        return rt;
    }

protected:
    void pushHp(vector<pair<Interval,vector<int>>> & vc, Interval & tv, int i, int j){// min by Interval end
        int k=vc.size();
        vector<int> se={i,j};
        pair<Interval,vector<int>> pr;
        vc.push_back(make_pair(tv,se));
        while(0<k){// bottom-up
            if(vc[k].first.start<vc[(k-1)/2].first.start){
                pr=vc[(k-1)/2];
                vc[(k-1)/2]=vc[k];
                vc[k]=pr;
                k=(k-1)/2;
            }else{
                return ;
            }
        }
        return ;
    }
 
    void topDown(vector<pair<Interval,vector<int>>> & vc){
        int k=0;
        pair<Interval,vector<int>> pr;
        while(2*k+2<vc.size()){
            if(vc[2*k+1].first.start<vc[k].first.start&&vc[2*k+1].first.start<vc[2*k+2].first.start){
                pr=vc[2*k+1];
                vc[2*k+1]=vc[k];
                vc[k]=pr;
                k=2*k+1;
            }else if(vc[2*k+2].first.start<vc[k].first.start){
                pr=vc[2*k+2];
                vc[2*k+2]=vc[k];
                vc[k]=pr;
                k=2*k+2;                
            }else{
                return ;
            }
        }
        
        if(2*k+1<vc.size()&&vc[2*k+1].first.start<vc[k].first.start){
            pr=vc[2*k+1];
            vc[2*k+1]=vc[k];
            vc[k]=pr;
        }
        
        return ;
    }
    
    void rlpHp(vector<pair<Interval,vector<int>>> & vc, Interval & tv, int i, int j){
        //cout<<i<<" "<<j<<" rlp "<<tv.start<<" "<<tv.end<<endl;
        vector<int> se={i,j};
        vc[0]=make_pair(tv,se);
        topDown(vc);
        return ;
    }
    
    void popHp(vector<pair<Interval,vector<int>>> & vc){
        vc[0]=vc.back();
        vc.pop_back();
        topDown(vc);
        return ;
    }
    
};
