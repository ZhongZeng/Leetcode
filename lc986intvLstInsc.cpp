/*
986. Interval List Intersections

Related Topics:	Two Pointers 

Test Cases:
[[0,2],[5,10],[13,23],[24,25]]
[[1,5],[8,12],[15,24],[25,26]]
[[3,10]]
[[5,10]]

Runtime: 32 ms
Memory Usage: 942.1 KB

Runtime: 28 ms

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
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        // 2-pointer 
        vector<Interval> rt;
        int i, j;
        
        for( i=0, j=0; i<A.size()&&j<B.size(); ){
            if(A[i].end<B[j].end){
                if( B[j].start<=A[i].end )
                    rt.push_back(Interval( B[j].start<A[i].start?A[i].start:B[j].start, A[i].end ));
                i++;
            }else{
                if( A[i].start<=B[j].end )
                    rt.push_back(Interval( B[j].start<A[i].start?A[i].start:B[j].start, B[j].end ));
                j++;
            }
        }
        
        return rt;
    }
};