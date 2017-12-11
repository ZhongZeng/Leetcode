/*

Leetcode 452. Minimum Number of Arrows to Burst Balloons

Related Topics 
Greedy 
Similar Questions 
Meeting Rooms II Non-overlapping Intervals 

Test Cases:
[[10,16],[2,8],[1,6],[7,12]]
[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]

Runtime: 112 ms
Your runtime beats 9.04 % of cpp submissions.
Runtime: 99 ms
Your runtime beats 19.90 % of cpp submissions.

*/

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        // sort (merge sort implemented here); greedy 
        // O(nlg(n)) time 
        // last ballon needs to be bursted; better shoot arrow at its start. 
        // classic greedy, very similar to Leetcode 435. Non-overlapping Intervals
        if(points.size()<1) return 0;
        int num=1, lst;
        mergeSort(points, 0, points.size());
        //for(auto ele : points)  cout<<ele.first<<"-"<<ele.second<<" ";
        
        lst=points.back().first;
        for(int i=points.size()-1; i!=-1; i--){
            if(points[i].second<lst){
                lst=points[i].first;
                num++;
            }
        }
        
        return num;
    }

protected:    
    void mergeSort(vector<pair<int, int>>& points, int bg, int ed){
        // [be,ed)
        // if sort by first/second, traverse from end/begin
        if(2<ed-bg){
            int mid=bg+(ed-bg)/2;
            mergeSort(points, bg, mid);
            mergeSort(points, mid, ed);
            merge(points, bg, mid, ed);
        }else if(ed-bg<2){
            
        }else if(points[bg+1].first<points[bg].first){ // ed-be==2
            pair<int,int> pr=points[bg];
            points[bg]=points[bg+1];
            points[bg+1]=pr;
        }
        return ;
    }
    
    
    void merge(vector<pair<int, int>>& points, int bg, int mid, int ed){
        vector<pair<int,int>> vc;
        for(int i=bg; i!=mid; i++)   vc.push_back(points[i]);
        
        for(int i=bg, j=0, k=mid; j!=mid-bg; i++){
            if(vc[j].first<points[k].first||k==ed){
                points[i]=vc[j];
                j++;
            }else{
                points[i]=points[k];
                k++;
            }
        }
        
        return ;
    }
    
};
